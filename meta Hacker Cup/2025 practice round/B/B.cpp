/**
 *    author: Saurav
 *    created: 2025.10.15 21:40:40
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
#define printset(s)
#define printpp(v)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
// #define ld long double
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    vector<vector<char> > grid(n, vector<char>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int> > dist(n, vector<int> (m, 1e9));
    queue<pp> q;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '#'){
                dist[i][j] = -1;
                q.push({i,j});
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if((i == 0 or i == n-1 or j == 0 or j == m-1) and grid[i][j] == '.'){
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        pp node = q.front();
        q.pop();
        int x = node.first;
        int y = node.second;
        vector<pp> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto dir: directions){
            int newx = x + dir.first;
            int newy = y + dir.second;
            if(newx >= 0 and newx < n and newy >= 0 and newy < m){
                if(dist[newx][newy] > 1e8){
                    dist[newx][newy] = dist[x][y] + 1;
                    q.push({newx, newy});
                }
            }
        }
    }

    vector<vector<char> > ans(n, vector<char> (m, '.'));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(dist[i][j] >= k){
                ans[i][j] = '*';
            }
        }
    }

    int res = 0;
    vector<vector<int> > visited(n, vector<int> (m, 0));

    // print2d(ans);
    // print2d(dist);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(ans[i][j] == '*' and visited[i][j] == 0){
                int curr = 0;
                queue<pp> q;
                q.push({i,j});
                visited[i][j] = 1;
                curr++;
                while(!q.empty()){
                    pp node = q.front();
                    q.pop();
                    int x = node.first;
                    int y = node.second;
                    vector<pp> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
                    for(auto dir: directions){
                        int newx = x + dir.first;
                        int newy = y + dir.second;
                        if(newx >= 0 and newx < n and newy >= 0 and newy < m){
                            if(ans[newx][newy] == '*' and visited[newx][newy] == 0){
                                visited[newx][newy] = 1;
                                q.push({newx, newy});
                                curr++;
                            }
                        }
                    }
                }
                res = max(res, curr);
            }
        }
    }

    cout<<res<<endl;
}
/* logic ends */

void main_() {
    // implement your solution here
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}

static void run_main() {
    main_();
    exit(0);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    size_t stsize = 1024ULL * 1024ULL * 1024ULL; // 1 GiB stack
    char *stack = (char *)malloc(stsize);
    if (!stack) {
        cerr << "Failed to allocate stack memory\n";
        return 1;
    }

    char *send = stack + stsize;
    // Align to 16 bytes (required by AArch64 ABI)
    send = (char *)((uintptr_t)send & -16LL);

#if defined(__aarch64__)
    asm volatile(
        "mov sp, %0\n"     // Set new stack pointer (sp = send)
        "blr %1\n"         // Branch with link to run_main
        :
        : "r"(send), "r"(run_main)
        : "sp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x30"
    );
#else
    // fallback for x86 or others
    asm volatile(
        "mov %0, %%rsp\n"
        "call *%1\n"
        :
        : "r"(send), "r"(run_main)
    );
#endif
    return 0;
}
