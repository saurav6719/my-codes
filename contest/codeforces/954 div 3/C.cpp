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
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    vector<int> indx(m);
    for(int i = 0; i<m; i++){
        int a;
        cin>>a;
        a--;
        indx[i] = a;
    }

    string c;
    cin>>c;
    set<int> st;
    for(auto ele : indx){
        st.insert(ele);
    }
    sort(c.begin(), c.end());
    vector<int> v;
    for(auto ele : st){
        v.push_back(ele);
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i<v.size(); i++){
        str[v[i]] = c[i];
    }

    cout<<str<<endl;
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

