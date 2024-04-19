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
void solve(set<int> &st){
    int n;
    cin>>n;
    if(n<7){
        cout<<"NO"<<endl;
        return;
    }  
    if(st.count(n)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;


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
    set<int> st;
    for(int i = 2;i<=1e6; i++){
        int start = 1+i+(i*i);
        int start_copy = start;
        st.insert(start_copy);
        start = i*i;
        if(start <=1e6) start = start * i;
        while(start_copy<=1e6){
            st.insert(start_copy);
            start_copy += start;
            start *= i;
        }
    }
    while(t--){
        solve(st);
    }
return 0;
}

