/**
 *    author: Saurav
 *    created: 2025.04.16 21:47:59
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
    int n;
    cin>>n;
    vector<vector<int>> grid(n, vector<int> (n));
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j<n; j++){
            cin>>grid[i][j];
        }
    }

    set<int> k_contenders;
    
    for(auto ele : grid[0]){
        k_contenders.insert(ele);
        k_contenders.insert(ele-1);
        k_contenders.insert(ele+1);
    }

    vector<int> ks;
    for(auto ele : k_contenders){
        ks.push_back(ele);
    }
    sort(ks.begin(), ks.end());
    print(ks);

    map<int,int> mp2;

    
        for(int i = 0; i<n; i++){
            vector<int> v = grid[0];
            sort(v.begin(), v.end());
            int j = 0; // ks pointer
            int k = 0; // v pointer
            int currsum = 0;

            while(j<ks.size() and k < v.size()){
                while(v[k] <= ks[j]){
                    currsum += v[k];
                    k++;
                }
                mp2[ks[j]] += currsum;
                mp2[ks[j]] += (n-k)*ks[j];
                j++;
            }

        }

        printmap(mp2);
    

    map<int,int> mp;

    for(int i = 1; i<n; i++){
        vector<int> v = grid[i];
        sort(v.begin(), v.end());
        int j = 0; // ks pointer
        int k = 0; // v pointer
        int currsum = 0;
        int thiss = 0;
        while(j<ks.size() and k < v.size()){
            while(v[k] <= ks[j]){
                currsum += v[k];
                k++;
            }
            thiss += currsum;
            thiss += (n-k)*ks[j];

            if(thiss > mp2[ks[j]]){
                mp[ks[j]]++;
            }
            j++;
        }
    }

    debug(mp[6]);

    int ans = 0;
    int reqk = -1;
    for(auto ele : mp){
        if(ele.second > ans){
            ans = ele.second;
            reqk = ele.first;
        }
    }

    cout<<reqk<<endl;
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

