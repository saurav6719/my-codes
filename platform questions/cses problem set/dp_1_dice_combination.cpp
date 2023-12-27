#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;

vector<int> dp;

int ans(int k) {
    // base case 
    if(k<0) return 0;
    dp[0] = 1;
    dp[1] = 1;
    
    if (k == 0 or k == 1) return dp[k];
    
    if (k == 2) {
        if (dp[k] != -1) return dp[k];
        else dp[k] = ((ans(k - 1) % mod) + (ans(k - 2) % mod) % mod);
        return dp[k];
    }
    
    if (k == 3) {
        if (dp[k] != -1) return dp[k];
        else dp[k] = ((ans(k - 1) % mod) + (ans(k - 2) % mod) + (ans(k - 3) % mod)) % mod;
        return dp[k];
    }
    
    if (k == 4) {
        if (dp[k] != -1) return dp[k];
        else dp[k] = ((ans(k - 1) % mod) + (ans(k - 2) % mod) + (ans(k - 3) % mod) + (ans(k - 4) % mod)) % mod;
        return dp[k];
    }
    
    if (k == 5) {
        if (dp[k] != -1) return dp[k];
        else dp[k] = ((ans(k - 1) % mod) + (ans(k - 2) % mod) + (ans(k - 3) % mod) + (ans(k - 4) % mod) + (ans(k - 5) % mod)) % mod;
        return dp[k];
    }
    
    if (k == 6) {
        if (dp[k] != -1) return dp[k];
        else dp[k] = ((ans(k - 1) % mod) + (ans(k - 2) % mod) + (ans(k - 3) % mod) + (ans(k - 4) % mod) + (ans(k - 5) % mod) + (ans(k - 6) % mod)) % mod;
        return dp[k];
    }

    if (dp[k] != -1) return dp[k];
    else dp[k] = ((ans(k - 1) % mod) + (ans(k - 2) % mod) + (ans(k - 3) % mod) + (ans(k - 4) % mod) + (ans(k - 5) % mod) + (ans(k - 6) % mod)) % mod;
    
    return dp[k];
}

int main() {
    int n;
    dp.clear();
    cin >> n;
    dp.resize(n + 5, -1);
    
    cout << (ans(n) % mod);
    return 0;
}
