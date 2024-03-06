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
    vector<int> input(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i];
    }
    stack<int> st;
    st.push(1);
    vector<int> ans(n);
    ans[0] = 0;
    for(int i = 1; i<n; i++){
        debug(input[i]);
        debug(st.top());
        while((!st.empty() and input[i] <= input[st.top()-1])){
            st.pop();
        }

        if(st.empty()) {
            ans[i] = 0;
            st.push(i+1);
            continue;
        }

        if(input[i] > input[st.top()-1]){
            ans[i] = st.top();
            st.push(i+1);
        }
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
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

