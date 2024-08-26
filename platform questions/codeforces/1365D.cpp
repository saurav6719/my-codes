/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

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
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
void solve(){
    int n,m;
    cin>>n>>m;
    int goodcnt = 0;
    vector<vector<char> > input(n, vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
            if(input[i][j] == 'G') goodcnt++;
        }
    }

    if(goodcnt == 0){
        cout<<"Yes"<<endl;
        return;
    }



    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == 'B'){
                //left 
                if(j-1 >= 0 and input[i][j-1] == '.'){
                    input[i][j-1] = '#';
                }
                if(j-1 >= 0 and input[i][j-1] == 'G'){
                    cout<<"No"<<endl;
                    return;
                }
                //right
                if(j+1 < m and input[i][j+1] == '.'){
                    input[i][j+1] = '#';
                }
                if(j+1 < m and input[i][j+1] == 'G'){
                    cout<<"No"<<endl;
                    return;
                }
                //up 
                if(i-1 >= 0 and input[i-1][j] == '.'){
                    input[i-1][j] = '#';
                }
                if(i-1 >= 0 and input[i-1][j] == 'G'){
                    cout<<"No"<<endl;
                    return;
                }
                //down 
                if(i+1 < n and input[i+1][j] == '.'){
                    input[i+1][j] = '#';
                }
                if(i+1 < n and input[i+1][j] == 'G'){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }

    if(input[n-1][m-1] == '#'){
        cout<<"No"<<endl;
        return;
    }

    queue<pair<int,int> > qu;
    qu.push({n-1, m-1});
    vector<vector<int> > dp(n, vector<int> (m, -1));
    dp[n-1][m-1] = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == '#'){
                dp[i][j] = 0;
            }
        }
    }

    while(!qu.empty()){
        auto ff = qu.front();
        qu.pop();
        int x = ff.first;
        int y = ff.second;
        //up 
        if(isValid(x-1, y, n, m) and dp[x-1][y] == -1){
            dp[x-1][y] = 1;
            qu.push({x-1, y});
        }
        //down
        if(isValid(x+1, y, n, m) and dp[x+1][y] == -1){
            dp[x+1][y] = 1;
            qu.push({x+1, y});
        }
        //left 
        if(isValid(x, y-1, n, m) and dp[x][y-1] == -1){
            dp[x][y-1] = 1;
            qu.push({x, y-1});
        }
        //right
        if(isValid(x, y+1, n, m) and dp[x][y+1] == -1){
            dp[x][y+1] = 1;
            qu.push({x, y+1});
        }
    }


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == 'G'){
                if(dp[i][j] != 1){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

