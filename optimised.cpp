/**
 *    author: Saurav
 *    created: 2025.01.12 11:45:08
 **/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<array<int,2>> nodes;
    nodes.reserve(n);
    for (int i = 0; i < n; i++){
        nodes.push_back({a[i], i});
    }

    // Sort the nodes in descending order of value (if equal, then increasing index)
    sort(nodes.begin(), nodes.end(), [](auto &p, auto &q){
        if(p[0] != q[0])
            return p[0] > q[0];
        return p[1] < q[1];
    });

    vector<int> ans(n, 0);
 
        // Let M = k - 1, the number of "bad" elements allowed in the subarray.
        int M = k - 1;
 
        // Our order–statistics tree stores indices of elements with a higher value (bad indices).
        ordered_set<int> T;
 
        // Process indices in descending order by their value.
        for(auto &node: nodes){
            int idx = node[1];
            int best = 0;
 
            // r = number of bad indices (with a higher value) that are strictly before idx.
            int r = T.order_of_key(idx);
 
            // IMPORTANT: In 0-indexing the smallest left boundary is 0 (not 1).
            int L_min;
            if(r > M){
                // We want the (r - M)-th smallest bad index (0-indexed position (r-M-1))
                int pos = r - M - 1;
                int candidateBad = *T.find_by_order(pos);
                L_min = candidateBad + 1;
            } else {
                L_min = 0;
            }
 
            // Candidate left-boundaries: L_min and also all L = (bad index + 1)
            // for each bad index x (with x in [L_min, idx)) we can try L = x+1.
            vector<int> candL;
            candL.push_back(L_min);
 
            int countLeft = T.order_of_key(idx); // number of bad indices before idx
            // Only a few candidates (at most M many) need be considered.
            int numCandidates = min(countLeft, M);
            for (int j = 0; j < numCandidates; j++){
                int pos = countLeft - 1 - j;  // j-th largest among those < idx
                if(pos < 0) break;
                int badIdx = *T.find_by_order(pos);
                int candidateL = badIdx + 1;
                // Only add if candidateL is at least L_min.
                if(candidateL >= L_min)
                    candL.push_back(candidateL);
            }
 
            // Remove duplicates and sort candidate left indices.
            sort(candL.begin(), candL.end());
            candL.erase(unique(candL.begin(), candL.end()), candL.end());
 
            // For each candidate left boundary L, find the maximum R (>= idx) such that the subarray [L, R]
            // contains at most M bad indices.
            for (int L : candL){
                // Count of bad indices strictly before L.
                int cntBeforeL = T.order_of_key(L);
                // We are allowed a total of (M + cntBeforeL) bad indices up to R.
                int allowed = M + cntBeforeL;
                int totalInT = T.size();
                int R;
                if (allowed < totalInT){
                    // The (allowed+1)-th bad index (0-indexed at position allowed) is the first one we *cannot*
                    // include, so we set R to be one less than that bad index.
                    R = (*T.find_by_order(allowed)) - 1;
                } else {
                    R = n - 1;
                }
 
                // Make sure that the subarray [L, R] indeed contains idx.
                if(R < idx) continue;
                int len = R - L + 1;
                best = max(best, len);
            }
 
            if(best < k)
                ans[idx] = 0;
            else
                ans[idx] = best;
 
            // Insert idx into T so that it becomes a "bad" index for those later (with lower values).
            T.insert(idx);
        }
 
        // Print answers in original order (0-indexed; if you wish to output 1-indexed, add 1 accordingly).
        for (int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

