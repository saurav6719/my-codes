#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define ll long long int
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int> >input(n,vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
        }
    }
    bool flag = false;
    for(int i = 0;i<n;i++){
        if(input[i][0] == 1) flag = true;
        if(input[i][m-1] == 1) flag = true;
    }

    for(int j = 0;j<m;j++){
        if(input[0][j] == 1) flag = true;
        if(input[n-1][j] == 1) flag = true;
    }
    int ans;
    if(flag) ans = 2;
    else ans = 4;
    cout<<ans;

}
int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
    
    return 0;
}