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
    string str;
    cin>>str;
    int n = str.size();
    int i = 0;
    int cnt = 0;
    int ans = 0;

    vector<int> a;
    vector<int> b;

    for(int i = 0; i<n; i++){
        if(str[i] == 'A') a.push_back(i);
        else b.push_back(i);
    }
    //print(b);

    string copy = str;
    reverse(copy.begin(), copy.end());

    set<int> visited;

    for(int i = 0; i<n; ){
        debug(ans);
        if(str[i] == 'A'){
            int xx = upper_bound(b.begin(), b.end(), i) - b.begin();
            if(xx < b.size()) {
                // debug(b[xx]);
                ans += b[xx] - i;
                i = b[xx];
             }
            else break;
            
        }

        else{
            int xx = upper_bound(b.begin(), b.end(), i) - b.begin();
            if(xx+1 < b.size() and b[xx+1] > i){
                //debug(b[xx]);
                ans += b[xx+1] - i - 1;
                i = b[xx+1];
            }
            else {
                ans += n-1-i;
            }
        }
        i++;
    }
    cout<<ans<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #i
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

