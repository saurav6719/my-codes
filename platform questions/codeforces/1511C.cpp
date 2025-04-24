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
    int q;
    cin>>n>>q;
    vector<int> input(n);
    vector<int> queries(q);
    
    vector<int> mindx(51,-1);
    for(int i = 0 ; i<n; i++){
        cin>>input[i];
        if(mindx[input[i]] == -1){
            mindx[input[i]] = i + 1;
        }
    }
    //print(mindx);

    while(q--){
        int ele;
        cin>>ele;
        // debug(mindx[4]);
        // debug(ele);
        int xx = mindx[ele];
        cout<<mindx[ele]<<" ";
        
        for(int i = 1; i<=50; i++){
            if(mindx[i] < xx and mindx[i] != -1){
                mindx[i]++;
            }
            // if(mindx[i] != -1)debug(i);
            // if(mindx[i] != -1)debug(mindx[i]);
        }
        mindx[ele] = 1;
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

