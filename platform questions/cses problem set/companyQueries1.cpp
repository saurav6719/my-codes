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
    int n,q;
    cin>>n>>q;
    vector<vector<int> > tree(n+5);

    for(int i = 2 ; i<=n; i++){
        int a;
        cin>>a;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }

    int limit = log2(n);

    vector<vector<int> > boss(n+5, vector<int> (limit+5));

    for(int k = 0; k<=limit; k++){
        boss[1][k] = -1;
    }


    for(int i = 2; i<=n; i++){
        boss[i][0] = tree[i][0];
    }




    for(int i = 2; i<=n; i++){
        for(int k = 1; k<=limit; k++){
            int ele = boss[i][k-1];
            if(ele == -1){
                boss[i][k] = -1;
                continue;
            }
            boss[i][k] = boss[ele][k-1];
        }
    }
    while(q--){
        int x;
        cin>>x;
        int k;
        cin>>k;

        if(x==1){
            cout<<-1<<endl;
            continue;
        }
        int ans;
        while(k>0){
            int bit = log2(k);
            ans = boss[x][bit];
            if(ans == -1) {
                x=-1;
                break;
            }
            x = ans;
            k -= (1<<bit);
        }
        cout<<x<<endl;
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

