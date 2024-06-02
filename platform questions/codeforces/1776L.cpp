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

std::pair<int, int> smallest_ratio(int a, int b) {
    int gcd = std::gcd(a, b);
    int x = a / gcd;
    int y = b / gcd;
    return std::make_pair(x, y);
}


void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int plus = 0;
    int minus = 0;
    for(int i = 0; i<n; i++){
        if(str[i] == '+') plus++;
        else minus ++;
    }
    int x = min(plus, minus);
    int y = max(plus, minus);
    set<pair<int,int> > st;
    while(x>0 and y>0){
        pair<int,int> xx = smallest_ratio(x,y);
        st.insert(xx);
        x--;
        y--;
    }

    // for(auto ele : st){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }

    int q;
    cin>>q;
    while(q--){

        int a;
        cin>>a;
        int b;
        cin>>b;

        if(x==y){
            cout<<"YES"<<endl;
            continue;
        }

        int aa = min(a,b);
        int bb = max(a,b);

        pair<int,int> yy = smallest_ratio(aa,bb);
        if(st.count(yy)){
            cout<<"YES"<<endl;
    
        }
        else cout<<"NO"<<endl;
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

