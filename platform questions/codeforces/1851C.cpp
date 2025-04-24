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
    int n,k;
    cin>>n>>k;
    vector<int> input(n);
    for(int i = 0 ;i<n; i++){
        cin>>input[i];
    }
    bool samec = (input[0] == input[n-1]);
    if(samec){
        int cnt = 2;
        int i = 0; 
        int j = n-1;
        for(int a = i+1; a<j; a++){
            if(input[a] == input[0]){
                cnt++;
            }
            if(cnt >= k) {
                cout<< "YES"<<endl;
                return;
            }
        }
        if(cnt >= k) {
                cout<< "YES"<<endl;
                return;
            }
    }
    else{
        if(k==1){
            cout<<"YES"<<endl;
            return;
        }
        int cnt1 = 0;
        int cnt2 =0;
        int x = -1;
        int y = -1;
        for(int a = 1; a<n;a++){
            if(input[a] == input[0]){
                cnt1++;
            }
            if(cnt1 == k-1) {
                x= a;
                break;
            }
        }
        for(int b = n-2; b>=0;b--){
            if(input[b] == input[n-1]){
                cnt2++;
            }
            if(cnt2 == k-1) {
                y=b;
                break;
            }
        }
        if(x<y and x!=-1 and y!=-1){
            cout<<"YES"<<endl;
            return;

        }
    }
    cout<<"NO"<<endl;
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