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
void f(vector<int> ans, int n, int i, int arr[]){
    //base case 
    if(i==n) { // print
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    f(ans,n,i+1,arr);
    if(ans.size() == 0 or ans[ans.size() - 1] == arr[i-1]){
        ans.push_back(arr[i]);
        f(ans,n,i+1,arr);
    }
}
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/ sizeof(arr[0]);
    vector<int> ans;
    f(ans,n,0,arr);

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