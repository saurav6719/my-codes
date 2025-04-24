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

bool cmp (int a,int b){
    return a>b;
}
bool flag = false;
int ans(int n, int m, int k, vector<int> &arr, int i){
    // base case
    int sum = 0;
    for(int ind = i; ind<n; ind++){
        sum += arr[ind];
    }
    if(k==0 and m> sum - (n-i-1)) {
        flag = true;
        return -1;  
    }
    if(k>0 and m > (sum + k -1)){
        flag = true;
        return -1;  
    }
    if(m<=0) return 0;
    if(k>=m) return 0;
    if(m<=arr[i]) return 1;
    if(k>1) return 1 + ans(n,m-arr[i],k-1,arr,i+1);
    if(k>=0 and m>arr[i]) return 1+ ans(n,m-arr[i] + 1, k-1,arr,i+1);
    if(k<0 and m>arr[i]) return 1+ ans(n,m-arr[i] + 1, k-1,arr,i+1);
    
    
}
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end(),cmp);
    int res = ans(n,m,k,input,0);
    if(flag) cout<<-1;
    else cout<<res;
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