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
    vector<int> input(n+1);
    for(int i = 1; i<=n; i++){
        cin>>input[i];
    }

    vector<vector<int> >store(n+5, vector<int> ());
    for(int i = 0; i<n+5; i++){
        store[i].push_back(0);
    }

    for(int i = 1; i<=n; i++){
        int ele = input[i];
        store[ele].push_back(i);
    }

    for(int i = 0; i<n+5; i++){
        store[i].push_back(n+1);
    }


    vector<int> ans(n+1, -1);

    vector<pair<int,int> > pp;

    for(int i = 1 ; i<=n; i++){
        if(store[i].size() == 2) continue;
        int diff = INT_MIN;
        for(int j = 1; j<store[i].size(); j++){
            diff = max(store[i][j] - store[i][j-1] , diff);
        }
        pp.push_back({diff, i});
    }

    for(auto ele : pp){
        int ff = ele.first;
        int ss = ele.second;
        for(int i = ff; i<=n; i++){
            if(ans[i] != -1)break;
            ans[i] = ss;
        }
    }

    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

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

