#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    int mini = INT_MAX;
    int maxi = INT_MIN;
    bool flag = false;
    for(int i = 0; i<n; i++){
        int ele ;
        cin>>ele;
        if(ele>=0) flag = true;
        input[i] = ele;
        mini = min(mini,ele);
        maxi = max(maxi,ele);
    }
    if(!flag){
        int sum2 = 0;
        int res = INT_MIN;
        for(int i = 0; i<n; i++){
            sum2 += input[i];
            if(sum2<maxi) sum2 = maxi;
            res = max(res,sum2);
        }
        cout<<res;
        return;
    }
    else{
        int sum = 0;
        int res = INT_MIN;
        for(int i = 0; i<n; i++){
            sum += input[i];
            if(sum<0) sum = 0;
            res = max(res,sum);
        }
        cout<<res;
        return;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}