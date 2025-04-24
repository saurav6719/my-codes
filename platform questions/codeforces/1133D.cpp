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

#include <iomanip>
#include <sstream>

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
using namespace std;

/* write core logic here */

#define x first
#define y second

void norm(pair<int, int> &p)
{
    if (p.x < 0)
    {
        p.x *= -1;
        p.y *= -1;
    }
    else if (p.x == 0 && p.y < 0)
    {
        p.y *= -1;
    }
    int d = __gcd(abs(p.x), abs(p.y));
    p.x /= d;
    p.y /= d;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    map<pair<int, int>, int> m;
    int ans = 0;
    int cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (b[i] == 0)
                cnt0++;
        }
        else
        {
            pair<int, int> p = make_pair(-b[i], a[i]);
            norm(p);
            m[p]++;
            ans = max(ans, m[p]);
        }
    }
    cout << cnt0 + ans << endl;
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
