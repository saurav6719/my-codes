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
bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void solve(){
    int n;
    cin>>n;
    int ans  =n*(n+1)/2;

    int m;
    cin>>m;
    vector<pair<int,int> > input(m);
    for(int i = 0; i<m; i++){
        int a;
        int b;
        cin>>a>>b;
        input[i].first = min(a,b);
        input[i].second = max(a,b);
    }

    sort(input.begin(), input.end(), cmp);

    int mini = n;
    for(int i = m-1; i>=0; i--){
        int ff = input[i].first;
        int ss = input[i].second;
        if(ss <= mini){
            ans -= ((mini - ss + 1) * ff);
            mini = ss - 1;
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

