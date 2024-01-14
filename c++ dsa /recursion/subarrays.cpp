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
    int arr[] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            for(int k = i; k<=j;k++){
                cout<<arr[k];
            }
            cout<<endl;
        }
    }
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