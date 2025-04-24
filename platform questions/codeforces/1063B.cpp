
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

void bfs(vector<vector<char>> &grid, vector<vector<char>> &ans, int sr, int sc, int left, int right, int n, int m) {
    deque<pair<int, int>> q;
    q.push_back({sr, sc});
    ans[sr][sc] = '+';

    // To track the number of left and right moves taken
    vector<vector<pair<int, int>>> moves(n, vector<pair<int, int>>(m, {0, 0}));
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop_front();

        int left_used = moves[r][c].first;
        int right_used = moves[r][c].second;

        // Prioritize Up and Down first

        // Up
        if (r - 1 >= 0 && grid[r - 1][c] != '*' && ans[r - 1][c] == '-') {
            ans[r - 1][c] = '+';
            moves[r - 1][c] = {left_used, right_used};  // Preserve left and right move consumption
            q.push_front({r - 1, c});  // Push to front to prioritize vertical moves
        }

        // Down
        if (r + 1 < n && grid[r + 1][c] != '*' && ans[r + 1][c] == '-') {
            ans[r + 1][c] = '+';
            moves[r + 1][c] = {left_used, right_used};  // Preserve left and right move consumption
            q.push_front({r + 1, c});  // Push to front to prioritize vertical moves
        }

        // Then, process Left and Right moves
        // Left (only if there are remaining left moves)
        if (c - 1 >= 0 && grid[r][c - 1] != '*' && ans[r][c - 1] == '-' && left_used + 1 <= left) {
            ans[r][c - 1] = '+';
            moves[r][c - 1] = {left_used + 1, right_used};  // Increment left moves
            q.push_back({r, c - 1});  // Push to back to process after vertical moves
        }

        // Right (only if there are remaining right moves)
        if (c + 1 < m && grid[r][c + 1] != '*' && ans[r][c + 1] == '-' && right_used + 1 <= right) {
            ans[r][c + 1] = '+';
            moves[r][c + 1] = {left_used, right_used + 1};  // Increment right moves
            q.push_back({r, c + 1});  // Push to back to process after vertical moves
        }
    }
}




void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m, '*'));
    int sr, sc;
    cin >> sr >> sc;
    sr--, sc--; // Convert to zero-based indexing

    int left, right;
    cin >> left >> right;

    // Reading the grid input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    print2d(grid);

    vector<vector<char>> ans(n, vector<char>(m, '-')); // Zero-based indexing for ans

    bfs(grid, ans, sr, sc, left, right, n, m); // BFS instead of recursion

    int res = 0;
    // Counting reachable cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == '+') res++;
        }
    }

    print2d(ans);
    cout << res << endl;
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

