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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
vector<int> fib(46);
bool f(int n, int x, int y){
    if(n==1 ) return true;
    int req = fib[n];
    int leftspace = y-1;
    int rightspace = fib[n+1] - y;
    int upspace = x-1;
    int downspace = fib[n] - x;


    if(rightspace >= fib[n]){
        return f(n-1, y, x);
    }

    if(leftspace >= fib[n]){
        return f(n-1 , y-fib[n] , x);
    }

    if(upspace >= fib[n]){
        return f(n-1, x - fib[n] , y);
    }

    if(downspace >= fib[n]){
        return f(n-1, x, y);
    }

    return false;

}
void solve(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int y;cin>>y;


    if(n == 1){
        cout<<"YES"<<endl;
        return;
    }

    if(f(n,x,y)){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;


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
    // t = 1;

    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i<=45; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    while(t--){
        solve();
    }
return 0;
}

