#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> dp;
int ans(int n){
    // base case
    for(int i = 0 ; i<= 9; i++){
        dp[i] = 1;
    }
    for(int i = 10; i <= n; i++){
        vector<int> storeDigits;
        int n_copy = i;
        while(n_copy > 0){
            storeDigits.push_back(n_copy % 10);
            n_copy /= 10;
        }
        int result = INT_MAX;
        int size = storeDigits.size();
        for(int j = 0 ; j<size ; j++){
            if(storeDigits[j] == 0 )continue;
            result = min(result , dp[i - storeDigits[j]] + 1);
        }
        dp[i]= result;
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+5 , -1);
    cout<<ans(n);
    return 0;
}