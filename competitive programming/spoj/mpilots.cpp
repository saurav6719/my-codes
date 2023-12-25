#include<iostream>
#include<vector>

using namespace std;
int dp[10005][10005]; 
int f(vector<int> &a, vector<int> &c, int i, int x){
    if(dp[i][x] != -1) return dp[i][x];
    if(i==a.size()) return 0;
    if(x==0){
        return dp[i][x] = f(a,c,i+1,x+1) + a[i];
    }
    else if(x == a.size() - i){
        return dp[i][x] = c[i] + f(a,c,i+1,x-1);
    }
    else{
        return dp[i][x] = min((f(a,c,i+1,x+1) + a[i]), (c[i] + f(a,c,i+1,x-1)));
    }

}
int main(){
    int n;
    cin>>n;
    vector<int> assis(n);
    vector<int> capt(n);
    
    for(int i=0;i<n;i++){
        cin>>capt[i];
        cin>>assis[i];
    }

    int ans = assis[0]; // forts person always assistant

    for(int i = 0; i < 10005; i++){
        for(int j = 0; j < 10005; j++){
            dp[i][j] = -1;
        }
    }

    ans+=f(assis,capt,1,1);
    cout<<ans;
    return 0;
}