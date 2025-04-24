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
    vector<int> input(n-1);
    for(int i= 0; i<n-1; i++){
        cin>>input[i];
    }
    vector<char> color(n);
    for(int i = 0; i<n; i++){
        cin>>color[i];
    }

    vector<vector<int> > parent(n+1, vector<int> ());

    for(int i= 0; i<n-1; i++){
        int par = input[i];
        parent[par].push_back(i+2);
    }

    print(parent[5]);

    vector<pair<int,int> > map(n+1);


    vector<int> ans;

    for(int i = n; i>=1; i--){
        if(parent[i].size() == 0){
            if(color[i-1] == 'W') map[i] = {0,1};
            else map[i] = {1,0};
            continue;
        }
        int black = 0;
        int white = 0;
        for(int j = 0;j<parent[i].size(); j++){
            int child = parent[i][j];
            black += map[child].first;
            white += map[child].second;
        }
        if(color[i-1] == 'W') white++;
        else black++;
        map[i].first = black;
        map[i].second = white;
    }
    debug(map[7].first);
    for(int i = 1; i<=n; i++){
        if(map[i].first == map[i].second) ans.push_back(i);
    }
    cout<<ans.size()<<endl;

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

