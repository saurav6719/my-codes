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
    int q;
    cin>>q;
    multiset<int> left;
    multiset<int> right;
   for(int i = 0; i<q; i++){
        char ch;
        cin>>ch;
        int l;
        int r;
        cin>>l>>r;
        if(ch == '+'){
            left.insert(l);
            right.insert(r);
        }
        else{
            auto it = left.find(l);
            if (it != left.end()) {
                left.erase(it);
            }

            auto it2 = right.find(r);
            if (it2 != right.end()) {
                right.erase(it2);
            }
            
        }

        if(i==0){
            cout<<"NO"<<endl;
            continue;
        }

        if(left.empty() or right.empty()){
            cout<<"NO"<<endl;
            continue;
        }
        int xx = *(right.begin());
        int yy = *(left.rbegin());

        //debug(yy);

        if(xx < yy){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
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

