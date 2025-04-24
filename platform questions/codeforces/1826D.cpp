#include<bits/stdc++.h>
#include <chrono>  // Include the chrono library for time measurement

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
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> input(n+5);
    for(int i = 1; i<=n; i++){
        cin>>input[i];
    }

    vector<vector<int>> dp(n+5, vector<int>(4, 0));
    for(int i = 1; i<=n; i++){
        dp[i][0] = 0;
        dp[i][1] = max(dp[i-1][1], input[i] + i + dp[i-1][0]);
        dp[i][2] = max(dp[i-1][2], input[i] + dp[i-1][1]);
        dp[i][3] = max(dp[i-1][3], input[i] - i + dp[i-1][2]);
    }
    print2d(dp);
    cout << dp[n][3] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    
    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate the duration
    std::chrono::duration<double> elapsed = end - start;
    cout << "Time taken: " << elapsed.count() << " seconds" << endl;

    return 0;
}
