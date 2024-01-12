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

void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int r1;
    int c1;
    int r2;
    int c2;
    cin>>r1>>c1>>r2>>c2;
    int rook =0;
    int bishop = 0;
    int king = 0;
    if(r1==r2 and c1 == c2){
        king = 0;
        bishop = 0;
        rook = 0;
        return ;
    }

    if(r1 == r2 or c1 == c2) rook = 1;   // 8 1 8 8
    else rook = 2;

    if((r1+c1) % 2 != (r2+c2) % 2) bishop = 0;
    else if(abs(r1-r2) == abs(c1-c2)) bishop = 1;
    else bishop = 2;

    int a = abs(r1-r2);
    int b = abs(c1-c2);
    king = max(a,b);

    cout<<rook<<" "<<bishop<<" "<<king;

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