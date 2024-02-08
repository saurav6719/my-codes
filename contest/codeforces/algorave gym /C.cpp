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
    string str;
    cin>>str;
    string str1 = str;
    sort(str1.begin(), str1.end());
    //debug(str1);
    int i = 0;
    while(i<n){
        if(str[i] == str1[i]) i++;
        else break;
    }
    //debug(i);
    if(i==n){
        cout<<str<<endl;
        return;
    }
    bool flag = true;
    int mxa;
    for(int a = i; a<n; a++){
        
        if(str[a] == str1[i]) {
            //debug(a);
            if(flag) mxa = a;
            //debug(mxa);
            if((str[a-1]) <= str[mxa-1] ) {
                mxa = a;
                flag = false;
            }
            //debug(mxa);
        }
    }
    //debug(mxa);
    reverse(str.begin() + i, str.begin()+ mxa+1);
    cout<<str<<endl;

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