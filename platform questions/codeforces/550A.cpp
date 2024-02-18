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
    string input;
    cin>>input;
    int a=0; 
    int b=0;
    int c=0;
    for(int i = 0; i<input.size()-1; i++){
        if(input[i] == 'A' and input[i+1] == 'B'){
            a = 1;
            b=i;
            break;
        }
    }
    if(a==1){
        for(int i = b+2;i<input.size()-1; i++){
            if(input[i] == 'B' and input[i+1] == 'A'){
                c = 1;
            }
        }
    }
    if(c==1){
        cout<<"YES";
        return;
    }
    a = 0;
    for(int i = 0; i<input.size()-1; i++){
        if(input[i] == 'B' and input[i+1] == 'A'){
            a = 1;
            b=i;
            break;
        }
    }
    if(a==1){
        for(int i = b+2;i<input.size()-1; i++){
            if(input[i] == 'A' and input[i+1] == 'B'){
                c = 1;
            }
        }
    }
    if(c==1){
        cout<<"YES";
        return;
    }
    cout<<"NO";
    
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