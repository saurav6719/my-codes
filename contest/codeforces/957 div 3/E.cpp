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

    string str = to_string(n);
    while(str.size()<8){
        str+= str;
    }

    vector<int> store;
    string  n_copy = to_string(n);
    string n_copy2 = n_copy;

    for(int i = 1; i<=8; i++){
        store.push_back(stoi(str.substr(0, i)));
    }

    print(store);

    vector<pair<int,int> > ans;

    //debug(n_copy2.size());
    vector<string> v;
    for(int i= 0; i<8; i++){
        v.push_back(to_string(store[i]));
    }
    for(int i = 0; i<8; i++){
        for(int a = 1; a<=10000; a++){
            int xx = n*a;
            //debug(xx);
            int b = xx - store[i];
            //debug(b);
            if(b < a * n_copy2.size() and b>0 and a*n_copy2.size() - b == v[i].size()){
                ans.push_back({a,b});
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto ele : ans){
        cout<<ele.first<<" "<<ele.second<<endl;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

