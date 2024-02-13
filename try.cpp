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
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int i = 0;
    int j = n-1;
    while(i<n-1 and input[i] == input[i+1]) i++; // i last tak aa gya
    int c1 = i - 0 + 1; //itne barabar hais atrt me 
    int num1 = input[i]; // ye h number 1 hai 
    while(j > 0 and input[j] == input[j-1]) j--;
    int c2 = n-j;
    int num2 = input[j];
    if(i>=j) {
        cout<<0<<endl;
        return;
    }
    int ans = 0;
    if(num1 == num2){
        ans += j-i-1;
        cout<<ans<<endl;
        return;
    }
    int count = 0;
    if(c1 > c2){
        ans = n-c1;
    }
    else ans = n-c2;
    cout<<ans<<endl;
    return;




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