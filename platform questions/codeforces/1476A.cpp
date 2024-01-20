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

int32_t main(){
    int t;
    cin>>t;
    //t = 1;
    for(int i = 0; i<t; i++){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int ans;
        //if(i==129) cout<<n * k<<endl;
        if(n > k) {
            int less = n / k;
            if(n%k == 0) k *= less;
            else k *= (less+1);
        }
        if(n==k) {
            cout<<"1"<<endl;
            continue;
        }
        int quot = k / n;
        int remain = k % n;
        if(remain != 0){
            ans = quot + 1;
        }
        else ans = quot;
        cout<<ans<<endl;
    }
return 0;
}