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
void solve(){//ios_base::sync_with_stdio(false);cin.tie(NULL);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int lenght;
    if(x1 == x2) lenght = abs(y1-y2);
    else if(x1 == x3) lenght = abs(y1-y3);
    else if(x1 == x4) lenght = abs(y1-y4);
    cout<<(lenght * lenght)<<endl;
}
int32_t main(){
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}