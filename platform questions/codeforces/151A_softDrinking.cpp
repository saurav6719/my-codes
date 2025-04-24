#include<iostream>
#include<vector>
#include<algorithm>
#define mn(a,b,c) min(min(a,b),c)
using namespace std;
int main(){
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int softDrink = (k * l) / nl;
    int lime = c * d;
    int salt = p/np;
    int ans = mn(softDrink,lime,salt);
    ans /= n;
    cout<<ans;
    return 0;
}
