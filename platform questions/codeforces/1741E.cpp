/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

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

bool dfs(set<int> & visited, int curr, map<int,vector<int> > &mp, int target){
    // if(curr == target) return true;
    visited.insert( curr);
 
    for(auto child : mp[curr]){
        if(child == target) return true;
        if(!visited.count(child + 1)){
            bool xx = dfs(visited, child+1, mp, target);
            if(xx) return true;
        }
    }

    return false;

}
void solve(){
    int n ;
    cin>>n;
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    map<int,vector<int> > mp;
    for(int i = 0; i<n; i++){
        int ele = b[i];
        int left = i - ele;
        if(left >= 0) {
            mp[left].push_back(i);
        }
        int right = i + ele;
        if(right < n){
            mp[i].push_back(right);
        }
    }

    // for(auto ele : mp){
    //     cout<<ele.first<<" - > ";
    //     for(auto ele2 : ele.second){
    //         cout<<ele2<<" ";
    //     }
    //     cout<<endl;
    // }

    set<int> st;

    bool xx = dfs(st,0,mp,n-1);

    if(xx) {
        cout<<"YES"<<endl;
    }

    else{
        cout<<"NO"<<endl;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

