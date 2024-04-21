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
    vector<int> v1(n);
    for(int i = 0; i<n; i++){
        cin>>v1[i];
    }
    vector<int> v2(n);
    for(int i = 0; i<n; i++){
        cin>>v2[i];
    }

    vector<int> diff;
    for(int i = 0; i<n; i++){
        diff.push_back(v1[i] - v2[i]);
    }
    vector<int> diff_copy = diff;
    print(diff_copy);
    sort(diff.begin(), diff.end(), greater<int>());
    int top = diff[0];
    int cnt = 0;

    for(int i = 0; i<n; i++){
        if(diff[i] != top) break;
        cnt++; 
    }

    cout<<cnt<<endl;

    for(int i = 0; i<n; i++){
        if(diff_copy[i] == top){
            cout<<i+1<<" ";
        }
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
