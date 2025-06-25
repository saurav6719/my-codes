/**
 *    author: Saurav
 *    created: 2025.06.25 20:54:03
 *    We stop at Candidate Master in 2025
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define printset(s)
#define printpp(v)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i] > 0) mp[a[i]] = i;
    }
    set<int> s;
    for(auto x : a){
        if(x > 0) s.insert(x);
    }
    vector<vector<int> > tree(n);
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    deque<pp> v;
    map<int,int> mp2;
    map<int,int> mp3;
    // mp2[i] = maximum of all the neighbours of i
    for(int i = 0; i<n; i++){
        int maxi = 0;
        int khali = 0;
        for(auto neigh : tree[i]){
            if(a[neigh] > 0){
                maxi = max(maxi, a[neigh]);
            } else {
                khali++;
            }
        }
        if(i==2){
            debug(maxi);
            debug(khali);
        }

        if(a[i] == 0) v.push_back({maxi, khali});
        mp2[i] = maxi;
        mp3[i] = khali;
    }

    sort(v.begin(), v.end(), [](pp a, pp b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    for(auto ele : v){
        debug(ele.first);
        debug(ele.second);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int pichekhali = 0;

    for(int i = 1; i<=n; i++){

        // jitne bhi nodes ka maximum i hai uske khali ko pq me add kro 
        while(!v.empty() && v.front().first < i){
            pq.push(v.front().second);
            v.pop_front();
        }
        // can i be the answer
        if(s.count(i)){
            // set me i hai 
            // is node ka max nikalo 
            int node = mp[i];
            if(i == 3){
                debug(node);
            }
            int currmaxi = mp2[node];
            if(i == 3){
                debug(currmaxi);
            }
            if(currmaxi < i){
                int currkhali = mp3[node];
                if(currkhali <= pichekhali){
                    cout<<i<<endl;
                    return;
                }
            }
        }
        else{
            // set me i nhi hai 
            // koi aisha node dhundho jiska maxi < i ho and khali <= pichekhali ho 
            if(!pq.empty()){
                int smallestkhali = pq.top();
                if(smallestkhali <= pichekhali){
                    cout<<i<<endl;
                    return; 
                }
            }
        }

        // pichekhali update kro
        if(s.count(i) == 0){
            pichekhali++;
        }
    }

    cout<<n+1<<endl; // if all nodes are present then answer is n+1
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

