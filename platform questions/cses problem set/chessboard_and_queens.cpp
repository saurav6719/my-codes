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
int ans = 0;
bool cango(vector<vector<char> > &input, int r, int c){
    // blocked
    if(r<0 or r>=8 or c<0 or c>=8) return false;
    if(input[r][c] == '*') return false;
    //check column 
    for(int i = 0; i<r; i++){
        if(input[i][c] == 'Q') return false;
    }
    //check left diagonal
    int i = r-1;
    int j = c-1;
    while(i>=0 and j>=0){
        if(input[i][j] == 'Q') return false;
        i--;
        j--;
    }
    //check right diagonal
    int a = r-1;
    int b = c+1;
    while(a>=0 and b<8){
        if(input[a][b] == 'Q') return false;
        a--;
        b++;
    }
    return true;
}
void f(vector<vector<char> > &input, int r){
    if(r==8){
        ans++;
        return;
    }
    for(int i = 0; i<8;i++){
        if(cango(input,r,i)){
            input[r][i] = 'Q';
            f(input,r+1);
            input[r][i] = '.';
        }
    }
}
void solve(){
    vector<vector<char> >input(8,vector<char> (8));
    for(int i= 0; i<8; i++){
        for(int j =0;j<8;j++){
            cin>>input[i][j];
        }
    }
    f(input,0);
    cout<<ans;

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