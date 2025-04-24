/**
 *    author: Saurav
 *    created: 2024.10.24 01:13:59
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
void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int> > input(n, vector<int>(m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char ch;
            cin>>ch;
            input[i][j] = ch - '0';
        }
    }

    vector<vector<int> > dp1(n, vector<int>(k+1,0)); // if ith day i skip j number of classes 

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=k; j++){
            // ith day i am skipping j classes
            // first find how many classes are there in ith day
            int total = 0;
            for(int l = 0; l<m; l++){
                if(input[i][l] == 1){
                    total ++;
                }
            }

            // if i have less classes than j then i don't need to go to college that day and skip all classes
            if(j >= total) {
                dp1[i][j] = 0;
                continue;
            }
            else{
                // i need to go to college that day and attend total - j classes
                // i will attend total - j consecutive classes 

                int ans = 1000;
                int l1 =0;
                int cnt = 0;
                while(l1<m and cnt < total-j){
                    if(input[i][l1] == 1){
                        cnt ++;
                    }
                    l1 ++;
                }
                if(cnt == total-j) ans = min(ans, l1);

                for(int x = 0; x<m; x++){
                    if(x>0 and input[i][x-1] == 1){
                        cnt--;
                    }
                    while(l1<m and cnt < total-j){
                        if(input[i][l1] == 1){
                            cnt ++;
                        }
                        l1 ++;
                    }   
                    if(cnt == total-j) ans = min(ans, l1-x);
                }

                dp1[i][j] = ans;
            }
        }
    }

    print2d(dp1);

    vector<vector<int> > dp2(n, vector<int>(k+1,0)); // dp[i][j] = i have attended till ith day and skipped j classes in total 

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=k; j++){
            // i decided to skip l classes on ith day 

            if(i==0){
                dp2[i][j] = dp1[i][j];
                continue;
            }

            dp2[i][j] = 1e9;

            for(int l = 0;l<=k; l++){
                dp2[i][j] = min(dp2[i][j] , dp1[i][l] + ((i-1 >=0 and j-l>=0 ) ? dp2[i-1][j-l]: 1000000000));
            }
        }
    }

    print2d(dp2);

    cout<<dp2[n-1][k]<<endl;
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

