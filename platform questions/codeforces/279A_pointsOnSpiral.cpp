#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
int f(int x, int y){
    if(x==0 and y==0) return 0;
    if(x==1 and y==0) return 0;
    if(x>0 and y> (-1*x + 1) and y<=x ) return 1+f(x,(-1 * (x-1)));
    if(y<0 and x>y and x<= (-1 * y) + 1) return 1+f(y,y);
    if(x<0 and y>=x and y< (-1 * x)) return 1+f(x,(-1*x));
    if(y>0 and x>= (-1*y) and x<y) return 1+ f(y,y);
}
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int x,y;
    cin>>x>>y;
    cout<< f(x,y);
}
int32_t main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}