/**
 *    author: Saurav
 *    created: 2024.10.14 14:35:33
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
int dp[100001][2][2];
void solve(){
    int n;
    cin>>n;
    vector<vector<char> >v(2, vector<char> (n+1));

    for(int i=0; i<2; i++){
        for(int j=1; j<=n; j++){
            cin>>v[i][j];
        }
    }

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<2; j++){
            for(int k = 0; k<2; k++){
                dp[i][j][k] = 0;
            }
        }
    }

    debug(dp[2][0][1]);

    dp[0][1][1] = 0;

    for(int i = 1; i<=n;i++){
        if(i-2 < 0) dp[i][1][0] = max((int) -1e15, dp[i][1][0]);
        else{
            bool win = false;
            int cnta = 0;
            int cntj = 0;
            if(v[0][i] == 'A') cnta ++;
            if(v[0][i-1] == 'A') cnta ++;
            if(v[1][i-1] == 'A') cnta ++;
            if(v[0][i] == 'J') cntj ++;
            if(v[0][i-1] == 'J') cntj ++;
            if(v[1][i-1] == 'J') cntj ++;
            if(cnta > cntj) win = true;

            dp[i][1][0] = max(dp[i][1][0]  , dp[i-2][1][1] + (win ? 1 : 0));
        }

        if(i-3 < 0) dp[i][1][0] = max((int) -1e15, dp[i][1][0]);
        else{
            bool win = false;
            int cnta = 0;
            int cntj = 0;
            if(v[0][i] == 'A') cnta ++;
            if(v[0][i-1] == 'A') cnta ++;
            if(v[0][i-2] == 'A') cnta ++;
            if(v[0][i] == 'J') cntj ++;
            if(v[0][i-1] == 'J') cntj ++;
            if(v[0][i-2] == 'J') cntj ++;
            if(cnta > cntj) win = true;
            if(i==7){
                debug(dp[i-3][1][0]);
                debug(win);
            }
            dp[i][1][0] = max(dp[i][1][0]  , dp[i-3][1][0] + (win ? 1 : 0));
            if(i==7){
                debug(dp[i][1][0]);
            }
            if(i==7){
                debug(dp[7][1][0]);
            }
        }

        if(i-3 < 0) dp[i][1][0] = max((int) -1e15, dp[i][1][0]);

        else{
            bool win = false;
            int cnta = 0;
            int cntj = 0;
            if(v[0][i] == 'A') cnta ++;
            if(v[0][i-1] == 'A') cnta ++;
            if(v[0][i-2] == 'A') cnta ++;
            if(v[0][i] == 'J') cntj ++;
            if(v[0][i-1] == 'J') cntj ++;
            if(v[0][i-2] == 'J') cntj ++;
            if(cnta > cntj) win = true;
            dp[i][1][0] = max(dp[i][1][0]  , dp[i-3][1][1] + (win ? 1 : 0));
        }


        if(i-2 < 0) dp[i][0][1] = max((int) -1e15, dp[i][0][1]);
        else{
            bool win = false;
            int cnta = 0;
            int cntj = 0;
            if(v[1][i] == 'A') cnta ++;
            if(v[1][i-1] == 'A') cnta ++;
            if(v[0][i-1] == 'A') cnta ++;
            if(v[1][i] == 'J') cntj ++;
            if(v[1][i-1] == 'J') cntj ++;
            if(v[0][i-1] == 'J') cntj ++;
            if(cnta > cntj) win = true;
            if(i==2) debug(dp[i-2][1][1]);
            if(i==2) debug(win);
            if(i==2) debug(dp[i][0][1]);

            dp[i][0][1] = max(dp[i][0][1]  , dp[i-2][1][1] + (win ? 1 : 0));
            if(i==2) debug(dp[i][0][1]);

        }

        if(i-3 < 0) dp[i][0][1] = max((int) -1e15, dp[i][0][1]);
        else{
            bool win = false;
            int cnta = 0;
            int cntj = 0;
            if(v[1][i] == 'A') cnta ++;
            if(v[1][i-1] == 'A') cnta ++;
            if(v[1][i-2] == 'A') cnta ++;
            if(v[1][i] == 'J') cntj ++;
            if(v[1][i-1] == 'J') cntj ++;
            if(v[1][i-2] == 'J') cntj ++;
            if(cnta > cntj) win = true;
            dp[i][0][1] = max(dp[i][0][1]  , dp[i-3][1][1] + (win ? 1 : 0));
        }

        if(i-3 < 0) dp[i][0][1] = max((int) -1e15, dp[i][0][1]);
        else{
            bool win = false;
            int cnta = 0;
            int cntj = 0;
            if(v[1][i] == 'A') cnta ++;
            if(v[1][i-1] == 'A') cnta ++;
            if(v[1][i-2] == 'A') cnta ++;
            if(v[1][i] == 'J') cntj ++;
            if(v[1][i-1] == 'J') cntj ++;
            if(v[1][i-2] == 'J') cntj ++;
            if(cnta > cntj) win = true;
            dp[i][0][1] = max(dp[i][0][1]  , dp[i-3][0][1] + (win ? 1 : 0));
        }

        if(i-2 < 0) dp[i][1][1] = max((int) -1e15, dp[i][1][1]);
        else{
            bool win = false;
            int cnta = 0;
            int cntj = 0;
            if(v[0][i] == 'A') cnta ++;
            if(v[1][i] == 'A') cnta ++;
            if(v[0][i-1] == 'A') cnta ++;
            if(v[0][i] == 'J') cntj ++;
            if(v[1][i] == 'J') cntj ++;
            if(v[0][i-1] == 'J') cntj ++;
            if(cnta > cntj) win = true;
            dp[i][1][1] = max(dp[i][1][1]  , dp[i-2][1][0] + (win ? 1 : 0) );
            dp[i][1][1] = max(dp[i][1][1] , dp[i-1][0][1] + (win ? 1 : 0) );
            if(i%3 != 0) dp[i][1][1] = 0;

        }
        if(i-3 < 0)dp[i][1][1] = max((int) -1e15, dp[i][1][1]);
        else{
            int win1 = 0;
            int win2 = 0;
            int cnta = 0;
            int cntj = 0;
            if(v[0][i] == 'A') cnta ++;
            if(v[0][i-1] == 'A') cnta ++;
            if(v[0][i-2] == 'A') cnta ++;
            if(v[0][i] == 'J') cntj ++;
            if(v[0][i-1] == 'J') cntj ++;
            if(v[0][i-2] == 'J') cntj ++;
            if(cnta > cntj) win1 = 1;

            cnta = 0;
            cntj = 0;

            if(v[1][i] == 'A') cnta ++;
            if(v[1][i-1] == 'A') cnta ++;
            if(v[1][i-2] == 'A') cnta ++;
            if(v[1][i] == 'J') cntj ++;
            if(v[1][i-1] == 'J') cntj ++;
            if(v[1][i-2] == 'J') cntj ++;
            if(cnta > cntj) win2 = 1;

            dp[i][1][1] = max(dp[i][1][1]  , dp[i-3][1][1] + win1 + win2);
            
            if(i%3 != 0) dp[i][1][1] = 0;
        }
    }

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<2; j++){
            for(int k = 0; k<2; k++){
                debug(i);
                debug(j);
                debug(k);
                debug(dp[i][j][k]);
            }
        }
    }
    int ans = dp[n][1][1];
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

