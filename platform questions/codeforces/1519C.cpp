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
    vector<int> u(n);
    for(int i = 0;i <n; i++){
        int uni;
        cin>>uni;
        u[i] = uni;
    }
    vector<vector<int> >universities(n+1, vector<int>());

    for(int i = 0; i<n; i++){
        int skill;
        cin>>skill;
        universities[u[i]].push_back(skill);
    }

    for(int i = 0; i<n+1; i++){
        sort(universities[i].begin(), universities[i].end(), greater<int> ());
    }

    for(int i = 0; i<n+1; i++){
        for(int j = 1; j<universities[i].size(); j++){
            universities[i][j] += universities[i][j-1];
        }
    }
    vector<int> ans(n+1,0);
    for(int i = 0; i<n+1; i++){
        for(int k = 1; k<=n; k++){
            if(k > universities[i].size()) break;
            int sz = universities[i].size();
            sz /= k;
            sz *= k;
            if(sz > 0 )sz--;
            ans[k] += universities[i][sz];
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

