/**
 *    author: Saurav
 *    created: 2024.11.04 08:05:47
 **/

#include <bits/stdc++.h>
using namespace std;

// Debugging macros
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)
#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif

#define endl "\n"
#define int long long
#define mod 1000000007
#define mn(a,b,c) min(a, min(b, c))
#define mx(a,b,c) max(a, max(b, c))
#define pp pair<int,int>

int dp[55][55][55];

// Recursive DP function
bool f(int i, int j, int k, vector<int> &input, int &currmask){
    // Base case: No elements to partition
    

    // Base case: Only one partition left
    if(k == 0){
        debug(i);
        debug(j);
        debug(currmask);
        return (((input[j] - (i > 0 ? input[i-1] : 0)) & currmask) == currmask);
    }

    if(i > j){
        return false;
    }

    // Memoization check
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    // Try all possible partition points
    bool ans = false;
    for(int x = i; x < j; x++){
        // Sum of current partition
        int current_sum = input[x] - (i > 0 ? input[i-1] : 0);
        
        if((current_sum & currmask) == currmask){
            ans = ans | f(x+1 , j, k-1, input, currmask);
        }
    }

    return dp[i][j][k] = ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> input(n);
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    // Compute prefix sums for efficient range sum queries
    for(int i = 1; i < n; i++){
        input[i] += input[i-1];
    }

    // Initialize DP array with -1
    for(int i = 0; i < 55; ++i)
        for(int j = 0; j < 55; ++j)
            for(int l = 0; l < 55; ++l)
                dp[i][j][l] = -1;

    // Compute and print the result
    int ans = 0;

    int xx = 24;

    // debug(f(0, n-1, k-1, input, xx));

    for(int i= 55; i>=0; i--){

        for(int i = 0; i < 55; ++i)
            for(int j = 0; j < 55; ++j)
                for(int l = 0; l < 55; ++l)
                    dp[i][j][l] = -1;
                    
        int currmask = ans | (1ll<<i);
        debug(currmask);
        if(f(0,n-1, k-1, input, currmask)){
            ans = currmask;
        }
    }

    cout<<ans<<endl;
}

#undef int // Undefine int to ensure main returns the correct type

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases are needed
    while(t--){
        solve();
    }
    return 0;
}
