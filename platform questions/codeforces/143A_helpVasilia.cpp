#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define ll long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int r1,r2,c1,c2,d1,d2;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    bool flag = true;
    for(int i = 1; i<=9;i++){
        int a = i;
        int b = r1-i;
        int c = c1-i;
        int d = d1-i;
        if(b>9 or c>9 or d>9) continue;
        if(b<1 or c<1 or d<1) continue;
        if(a== b or a==c or a==d or b==c or b==d or c==d ) continue;
        if(b+d == c2 and b+c == d2 and c+d == r2) {
            if(a!= b and b != c and c!= d){
                flag = false;
                cout<<a<<" "<<b<<endl<<c<<" "<<d;
                break;
            }
        }
    }
    if(flag) cout<<"-1";
}
int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
    solve();
    }
return 0;
}