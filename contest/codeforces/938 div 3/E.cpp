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

int n;
string str;

bool poss(int k, string &str){
    int i = 0;
    while(str[i] == '1') i++;
    int cnt = 0;
    set<int> st;
    for(; i<n; i++){
        if(st.count(i)) cnt --;
        if(str[i] == '1' and cnt % 2 == 0){
            continue;
        }
        if(str[i] == '0' and cnt % 2 == 1){
            continue;
        }
        if(i + k - 1 >= n) return false;
        st.insert(i+k);
        cnt++;
    }

    return true;
}
void solve(){
    
    cin>>n;
    
    cin>>str;
    int ans = 1;
    for(int i = n ; i>1; i--){
        if(poss(i,str)) {
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
    
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

