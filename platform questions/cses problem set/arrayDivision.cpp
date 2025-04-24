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
using namespace std;

/* write core logic here */

bool poss(int mid, vector<int> &input, int k)
{
    int cnt = 0;
    int aa = 0;
    for (int i = 0; i < input.size(); i++)
    {
        aa += input[i];
        if (aa > mid)
        {
            cnt++;
            aa = input[i];
        }
    }
    return cnt + 1 <= k;
}
void solve()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> input(n);
    int large = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        sum += input[i];
        large = max(large, input[i]);
    }
    int lo = large;
    int hi = sum;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (poss(mid, input, k))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans;
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
