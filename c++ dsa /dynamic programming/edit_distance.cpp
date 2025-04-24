#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
//link -> https://leetcode.com/problems/edit-distance/
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    class Solution {
public:
vector<vector<int> > dp;
int f(string &s1, string &s2, int i , int j){
    //base case 
    if(i==s1.size()) return s2.size()-j;

    if(j==s2.size()) return s1.size()-i;

    if(dp[i][j] != -1) return dp[i][j];


    if(s1[i] == s2[j]) return dp[i][j] = f(s1,s2,i+1,j+1);


    return dp[i][j] = min({1+f(s1,s2,i+1,j+1) , 1+f(s1,s2,i+1,j) , 1+f(s1,s2,i,j+1)});
}


    int minDistance(string word1, string word2) {
        dp.clear();
        dp.resize(505,vector<int> (505,-1));
        return f(word1,word2,0,0);
    }
};
}
int32_t main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}