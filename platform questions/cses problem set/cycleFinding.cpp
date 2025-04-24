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
#define print(v)                           \
    do                                     \
    {                                      \
        cout << "vect--" << #v << " = [ "; \
        for (int i = 0; i < v.size(); i++) \
        {                                  \
            cout << v[i] << " ";           \
        }                                  \
        cout << " ]" << endl;              \
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
#define pp pair<int, int>
using namespace std;
/* write core logic here */
struct edgelist
{
    int src;
    int dest;
    int weight;
};

void solve()
{
    int n;
    int m;
    cin >> n >> m;
    vector<vector<pp>> graph(n + 5, vector<pp>());
    vector<edgelist> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        edges.push_back({u, v, w});
    }
    vector<int> dist(n + 5, 0);
    vector<int> relaxation(n + 5, 0);
    for (int i = 0; i < m - 1; i++)
    {
        for (auto ele : edges)
        {
            int u = ele.src;
            int v = ele.dest;
            int w = ele.weight;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                relaxation[v] = u;
            }
        }
    }
    int x = -1;
    for (int i = 0; i < 1; i++)
    {
        for (auto ele : edges)
        {
            int u = ele.src;
            int v = ele.dest;
            int w = ele.weight;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                relaxation[v] = u;
                x = v; // node which is modified
            }
        }
    }
    if (x == -1)
    {
        // no relaxation after m-1 iterations
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    // traceback m times
    for (int i = 0; i < m; i++)
    {
        x = relaxation[x];
    }
    // now x is a node in the cycle ;
    int x_copy = x;
    vector<int> ans;
    ans.push_back(x);
    x = relaxation[x];
    while (x != x_copy)
    {
        ans.push_back(x);
        x = relaxation[x];
    }
    ans.push_back(x_copy);
    reverse(ans.begin(), ans.end());
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
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
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
