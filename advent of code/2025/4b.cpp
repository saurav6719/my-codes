/**
 *    author: Saurav
 *    created: 2025.12.05 18:52:48
 *    We stop at Candidate Master in 2025
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define printset(s)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    vector<string> input;
    string s;
    while(cin>>s){
        input.push_back(s);
    }
    int ans = 0;
    int n = input.size();
    int m = input[0].size();
    map<pp,int> mp;
    queue<pp> q;
    set<pp> visited;


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] != '@') continue;
            int cnt = 0;
            if(i-1 >= 0){
                // up row 
                if(input[i-1][j-1] == '@') cnt++;
                if(input[i-1][j] == '@') cnt++;
                if(input[i-1][j+1] == '@') cnt++;
            }
            // same row
            if(input[i][j-1] == '@') cnt++;
            if(input[i][j+1] == '@') cnt++;
            if(i+1 < n){
                // down row
                if(input[i+1][j-1] == '@') cnt++;
                if(input[i+1][j] == '@') cnt++; 
                if(input[i+1][j+1] == '@') cnt++;
            }

            mp[{i,j}] = cnt;

            if(cnt < 4) {
                q.push({i,j});
                visited.insert({i,j});
            }
        }
    }
    

    while(!q.empty()){
        auto top = q.front();
        q.pop();
        ans++;
        int x = top.first;
        int y = top.second;

        vector<pp> directions = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };
        for(auto ele : directions){
            int nextx = x + ele.first;
            int nexty = y + ele.second;
            if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
            if(input[nextx][nexty] != '@') continue;
            if(visited.find({nextx,nexty}) != visited.end()) continue;
            mp[{nextx,nexty}]--;
            if(mp[{nextx,nexty}] < 4){
                q.push({nextx,nexty});
                visited.insert({nextx,nexty});
            }
        }
    }

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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

