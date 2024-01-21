#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

void right_shift(vector<int> &b , bool flag ){
    int n = b.size();
    int x = b[n-1];
    if(x > n) {
        cout<<"No"<<endl;
        flag = false;
        return ;
    }
    x = x % n;
    reverse(b.begin(), b.end());
    reverse(b.begin(), b.begin()+x );
    reverse(b.begin() + x, b.end());
    return;
}
void solve(){
    bool flag = true;
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }
    if(b[b.size() - 1] >n){
        cout<<"No"<<endl;
        return;
    }
    if(n==1) {
        cout<<"Yes"<<endl;
        return;
    }

    while(k--){
        if(flag == false) return;
        right_shift(b, flag );
        k--;
    }

    cout<<"Yes"<<endl;


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}