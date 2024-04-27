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
void prf(vector<int> &pf, int n, multiset<int> &ms){
    for(int i = 2; i * i <= n ; i++){
        while(n % i == 0){
            pf.push_back(i);
            ms.insert(i);
            n /= i;
        }
    }
    if(n>1) {
        pf.push_back(n);
        ms.insert(n);
    } 
}
void solve(){
    int n;
    cin>>n;
    vector<int> pf;
    multiset<int> ms;
    prf(pf,n, ms);
    // for(auto ele : ms){
    //     cout<<ele<<" ";
    // }
    // cout<<endl;
    set<int> st;
    int x = 1;
    for(auto ele : ms){
        x *= ele;
        if(st.count(x) == 0){
            st.insert(x);
            x= 1;
        }
    }

    if(st.size() <3){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int cnt = 0;
    vector<int> v;
    for(auto ele : st){
        cout<<ele<<" ";
        cnt++;
        v.push_back(ele);
        if(cnt==2) break;
    }

    for(auto ele : v){
        st.erase(ele);
    }

    int last = 1;
    
    for(auto ele:v){
        last*=ele;
    }
    last = n/last;
    cout<<last<<endl;
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

