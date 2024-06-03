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

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr----  " << #x << " " << x << endl
#define print(v)                                \
    do                                          \
    {                                           \
        cout << "vect--" << #v << " = [ ";      \
        for (int i = 0; i < v.size(); i++)      \
        {                                       \
            cout << v[i] << " ";                \
        }                                       \
        cout << " ]" << endl;                   \
    } while (0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a, b, c) min(a, min(b, c))
#define mx(a, b, c) max(a, max(b, c))
using namespace std;

/* write core logic here */
int ans;

void bfs(int start_i, int start_j, int mindis, vector<pair<int, int>> &input)
{
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push({start_i, start_j});
    visited.insert({start_i, start_j});

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        int curr = 0;
        for (const auto &p : input)
        {
            curr += (abs(p.first - i) + abs(p.second - j));
        }

        if (curr == mindis)
            ans++;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto &dir : directions)
        {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (!visited.count({ni, nj}))
            {
                visited.insert({ni, nj});
                q.push({ni, nj});
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    ans = 0;

    int sumi = 0;
    int sumj = 0;

    vector<pair<int, int>> input(n);

    for (int i = 0; i < n; i++)
    {
        int elei;
        cin >> elei;
        sumi += elei;

        int elej;
        cin >> elej;
        sumj += elej;

        input[i] = {elei, elej};
    }

    int mini = sumi / n;
    int minj = sumj / n;

    int mindis = 0;

    for (int i = 0; i < n; i++)
    {
        mindis += (abs(input[i].first - mini) + abs(input[i].second - minj));
    }

    bfs(mini, minj, mindis, input);

    cout << ans << endl;
}
/* logic ends */

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
