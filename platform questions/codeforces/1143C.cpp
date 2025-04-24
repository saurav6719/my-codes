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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int> parent(n+1);
    vector<vector<int> > child(n+1);
    vector<int> respect(n+1);
    int root ;
    for(int i = 1; i<=n; i++){
        int xx;
        cin>>xx;
        if(xx == -1){
            root = i;
        }
        parent[i] = xx;
        if(xx!= -1) child[xx].push_back(i);
        cin>>respect[i];
    }

    vector<int> ans;
    for(int i = 1; i<=n; i++){
        if(i == root) continue;
        if(respect[i] == 0) continue;
        bool check = false;
        for(auto ele : child[i]){
            if(respect[ele] == 0){
                check = true;
                break;
            }
        }

        if(!check){
            ans.push_back(i);
        }
    }
    if(ans.size() == 0){
        cout<<-1;
        return;
    }
    for(auto ele: ans){
        cout<<ele<<" ";
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

