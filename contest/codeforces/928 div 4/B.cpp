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
    vector<vector<char> > input(n, vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>input[i][j];
        }
    }
    bool f = false;
    bool l = false;
    int fr = 0;
    int fc = 0;
    int lr = 0;
    int lc = 0;
    for(int i = 0; i<n; i++){
        if(f) break;
        for(int j = 0; j<n; j++){
            if(input[i][j] == '1'){
                f = true;
                fr = i;
                fc= j;
                break;
            }
        }
    }
    debug(fr);
    debug(fc);
    for(int i = n-1; i>=0; i--){
        if(l) break;
        for(int j = n-1; j>=0; j--){
            if(input[i][j] == '1'){
                l = true;
                lr = i;
                lc = j;
                break;
            }
        }
    }
    debug(lr);
    debug(lc);
    bool sqaure = true;
    for(int i = fr; i<= lr; i++){
        for(int j = fc; j<= lc; j++){
            if(input[i][j] == '0'){
                sqaure = false;
                break;
            }
        }
    }

    if(sqaure) cout<<"SQUARE"<<endl;
    else cout <<"TRIANGLE"<<endl;

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