/**
 *    author: Saurav
 *    created: 2024.11.12 21:48:55
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

    vector<vector<int> > query(n,vector<int>());

    for(int i = 0; i<n; i++){
        int type;
        cin>>type;
        if(type == 1){
            int x;
            cin>>x;
            query[i].push_back(type);
            query[i].push_back(x);
        }
        else{
            int x,y;
            cin>>x>>y;
            query[i].push_back(type);
            query[i].push_back(x);
            query[i].push_back(y);
        }
    }

    map<int,int> mp;

    vector<int> ans;

    for(int i = n-1; i>=0; i--){
        int type = query[i][0];

        if(type==1){
            int ele = query[i][1];
            if(mp.count(ele)){
                int newval = mp[ele];
                ans.push_back(newval);
            }
            else{
                ans.push_back(ele);
            }
        }
        else{
            int x = query[i][1];
            int y = query[i][2];

            if(mp.count(y)){
                mp[x] = mp[y];
            }
            else{
                mp[x] = y;
            }
        }
    }

    reverse(ans.begin(),ans.end());

    for(auto x : ans){
        cout<<x<<" ";
    }
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

