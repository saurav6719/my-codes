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
int power(int a, int x){ios_base::sync_with_stdio(false);cin.tie(NULL);
    //finding a to the power x

    if(x == 0) return 1;
    if(x%2 ==0) {
        int res = power(a,x/2);
        return res * res;
    }
    else{
        int res = power(a, (x-1) / 2);
        return res * res * a;
    }
}
int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        cout<<power(2,10);
    }
return 0;
}