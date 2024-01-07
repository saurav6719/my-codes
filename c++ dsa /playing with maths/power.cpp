#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
#define ll long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
int power(int a, int x, int p = mod){ios_base::sync_with_stdio(false);cin.tie(NULL);
    //finding a to the power x
    int res = 1;
    a = a % p;
    while(x>0){
        if(x & 1){                          
            res = (res * a) % p;
        }
        x = x >> 1;
        a = (a * a) % p;
    }
    return res;

}
int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        cout<<power(2,0);
    }
return 0;
}