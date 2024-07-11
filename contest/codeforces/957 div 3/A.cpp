
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
int f(int a, int b, int c, int cnt){
    if(cnt == 5) return a*b*c;
    int xx = f(a+1, b, c, cnt+1);
    int yy=  f(a, b+1, c, cnt+1);
    int zz = f(a,b,c+1, cnt+1);
    return mx(xx,yy,zz);
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans= INT_MIN;

cout<<f(a,b,c,0)<<endl;


    
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

