/**
 *    author: Saurav
 *    created: 2024.10.19 03:50:35
 **/

/* includes and all */

#include<bits/stdc++.h>
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
#define mod 998244353
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int dp[200001][2][2][4];

int f(int idx , int lasteven, int secondlasteven, int length,  vector<int> &input, int n){
    if(idx == n and length >= 3) return 1;
    if(idx == n) return 0;

    if(dp[idx][lasteven][secondlasteven][length] != -1) return dp[idx][lasteven][secondlasteven][length];

    int ans = 0;

    if(length == 0){
        int newlasteven = true;
        if(input[idx] & 1) newlasteven = false;
        ans += f(idx+1 , newlasteven , secondlasteven , length + 1 , input , n);
        ans %= mod;
    }
    else if(length == 1){
        int newlasteven = true;
        if(input[idx] & 1) newlasteven = false;
        ans += f(idx+1 , newlasteven , lasteven , length + 1 , input , n);
        ans %= mod;
    }
    else if (length ==2){
        if(lasteven == 0 and secondlasteven == 0){
            if(input[idx] % 2 ==0){
                ans += f(idx+1 , 1 , lasteven , length + 1 , input , n);
                ans %= mod;
            }
        }
        if(lasteven == 0 and secondlasteven == 1){
            if(input[idx] % 2 == 1){
                ans += f(idx +1, 0 , lasteven , length + 1 , input , n);
                ans %= mod;
            }
        }
        if(lasteven == 1 and secondlasteven == 1){
            if(input[idx] % 2 == 0){
                ans += f(idx +1, 1 , lasteven , length + 1 , input , n);
                ans %= mod;
            }
        }
        if(lasteven == 1 and secondlasteven == 0){
            if(input[idx] % 2 == 1){
                ans += f(idx+1 , 0 , lasteven , length + 1 , input , n);
                ans %= mod;
            }
        }
    }
    else if (length == 3){
        if(lasteven == 0 and secondlasteven == 0){
            if(input[idx] % 2 ==0){
                ans += f(idx +1, 1 , lasteven , 3 , input , n);
                ans %= mod;
            }
        }
        if(lasteven == 0 and secondlasteven == 1){
            if(input[idx] % 2 == 1){
                ans += f(idx +1, 0 , lasteven , 3 , input , n);
                ans %= mod;
            }
        }
        if(lasteven == 1 and secondlasteven == 1){
            if(input[idx] % 2 == 0){
                ans += f(idx +1, 1 , lasteven , 3 , input , n);
                ans %= mod;
            }
        }
        if(lasteven == 1 and secondlasteven == 0){
            if(input[idx] % 2 == 1){
                ans += f(idx+1 , 0 , lasteven , 3 , input , n);
                ans %= mod;
            }
        }
    }

    ans += f(idx + 1 , lasteven , secondlasteven , length , input , n);
    ans %= mod;

    return dp[idx][lasteven][secondlasteven][length] = ans;

}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    memset(dp , -1 , sizeof(dp));

    int ans = f(0,1,1,0,input,n);  

    cout<<ans<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

