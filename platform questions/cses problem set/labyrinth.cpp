/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav            |
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

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

int n, m;
vector<vector<bool>> visited;
vector<vector<char>> direction;
vector<vector<pair<int, int>>> parent;
int dr = -1, dc = -1;

void bfs(vector<vector<char>> &graph, int sr, int sc) {
    queue<pair<int, int>> qu;
    qu.push({sr, sc});
    visited[sr][sc] = true;

    while (!qu.empty()) {
        auto [r, c] = qu.front();
        qu.pop();

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<char> dirChars = {'D', 'U', 'R', 'L'};

        for (int k = 0; k < 4; ++k) {
            int nr = r + directions[k].first;
            int nc = c + directions[k].second;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                visited[nr][nc] = true;
                direction[nr][nc] = dirChars[k];
                parent[nr][nc] = {r, c};

                if (graph[nr][nc] == 'B') {
                    dr = nr;
                    dc = nc;
                    return;
                }
                
                if (graph[nr][nc] == '.') {
                    qu.push({nr, nc});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> input(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> input[i][j];
        }
    }

    visited.resize(n, vector<bool>(m, false));
    direction.resize(n, vector<char>(m, ' '));
    parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));

    int sr = -1, sc = -1;
    for (int i = 0; i < n && sr == -1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (input[i][j] == 'A') {
                sr = i;
                sc = j;
                break;
            }
        }
    }

    bfs(input, sr, sc);

    if (dr != -1) {
        string ans;
        int r = dr, c = dc;
        while (!(r == sr && c == sc)) {
            ans += direction[r][c];
            auto [pr, pc] = parent[r][c];
            r = pr;
            c = pc;
        }
        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
