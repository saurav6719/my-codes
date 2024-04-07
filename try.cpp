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
    vector<int> v(n) ;
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    print(v);
    multiset<int> st;
    for(int i = 0; i<n; i++){
        st.insert(v[i]);
    }
    for(auto ele: st){
        cout<<ele<<" ";
    }
    double cost = 0;
    
    while(st.size() != 1){
        double mini = *st.begin();
        double maxi = *st.rbegin();
        debug(mini);
        debug(maxi);
        cost += ceil((mini + maxi) / (maxi - mini + 1));
        debug(cost);
        auto it1 = st.begin();
        auto it2 = st.end();
        it2--;
        st.erase(it1);
        st.erase(it2);
        debug(st.size());
        st.insert(mini+maxi);  
    }

    cout<<cost<<endl;
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

