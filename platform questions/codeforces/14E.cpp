/**
 *    author: Saurav
 *    created: 2024.10.24 02:45:06
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
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int dp[21][6][6][11];
int f(int i , int last , int secondlast , int currhump, int n , int t){

    debug(i);
    debug(last);
    debug(secondlast);
    debug(currhump);

    if(i==n){
        if(currhump == t) return 1;
        return 0;
    }

    if(currhump > t) return 0;

    debug(dp[i][last][secondlast][currhump]);
    if(dp[i][last][secondlast][currhump] != -1) return dp[i][last][secondlast][currhump];

    // cout<<"yes"<<endl;


    int ans = 0;

    for(int j = 1; j<5; j++){

        // cout<<"yes"<<endl;
        if(j==last) continue;

        if(i==1){
            if(j<=last) continue;
        }

        if(i==n-1){
            if(j>=last) continue;
        }
        if(i>=2){
            if(j < last and last > secondlast){
                ans += f(i+1, j, last, currhump+1, n, t);
            }
            else{
                ans += f(i+1, j, last, currhump, n, t);
            }
        }
        else{
            ans += f(i+1, j, last, currhump, n, t);
        }
    }

    return dp[i][last][secondlast][currhump] = ans;
}

void solve(){
    int n;
    int t;
    cin>>n>>t;

    for(int i = 0; i<21; i++){
        for(int j = 0; j<6; j++){
            for(int k = 0; k<6; k++){
                for(int l = 0; l<11; l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }


    int ans = 0;

    ans = f(0,5,5,0,n,t);

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

