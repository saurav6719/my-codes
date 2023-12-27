#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
int dp[2005][2005][8];
int f(vector<int> &s1,vector<int> &s2, int i, int j, int k){
    if(i>= s1.size() or j>= s2.size()) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int result = 0;
    if (s1[i] == s2[j]) return dp[i][j][k] = 1 + f(s1,s2,i+1,j+1,k);
    if(k>0){
        result = 1+f(s1,s2,i+1,j+1,k-1);
    }
    return dp[i][j][k] = mx(result, f(s1,s2,i+1,j,k) , f(s1,s2,i,j+1,k));
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    memset(dp,-1,sizeof dp);
    vector<int> nums1(n);
    for(int i = 0; i< n ; i++){
        cin>>nums1[i];
    }
    vector<int> nums2(m);
    for(int i = 0; i< m ; i++){
        cin>>nums2[i];
    }
    cout<<f(nums1,nums2,0,0,k);
    return 0;
}