/*
Author : MadhavCoding
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double
#define pi pair<int, int>
#define pll pair<ll, ll>
#define endl "\n"

const ll MOD = 1e9 + 7;
const ll N = 1e5;

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, ll, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

ll maxexpo(ll a, ll b)
{
    ll res = 0;
    while(a >= b)
    {
        b *= 2;
        res++;
    }
    return res;
}

void solve()
{
    ll n, n1, n2, n3;
    cin>>n>>n1>>n2>>n3;

    ll x, y;
    cin>>x>>y;

    vector<vector<ll>> edges1, edges2, edges3;

    for (int i = 0; i < n1; i++)
    {
        ll u, v, p;
        vector<ll> vt(3);
        cin>>vt[0]>>vt[1]>>vt[2];
        vt[0]--; vt[1]--;
        edges1.push_back(vt);
    }
    for (int i = 0; i < n2; i++)
    {
        ll u, v, p;
        vector<ll> vt(3);
        cin>>vt[0]>>vt[1]>>vt[2];
        vt[0]--; vt[1]--;
        edges2.push_back(vt);
    }
    for (int i = 0; i < n3; i++)
    {
        ll u, v, p;
        vector<ll> vt(3);
        cin>>vt[0]>>vt[1]>>vt[2];
        vt[0]--; vt[1]--;
        edges3.push_back(vt);
    }
    
    ll req = maxexpo(x, y);
    if(req == 0)
    {
        cout<<0<<endl;
        return;
    }

    function<vector<vector<ll>> (vector<vector<ll>>&)> f = [&](vector<vector<ll>>& edges)
    {
        vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MIN));

        for(int i = 0; i < n; i++) dp[i][i] = 0;

        for(auto edge : edges)
        {
            ll u = edge[0], v = edge[1];
            ll p = edge[2];

            dp[u][v] = max(dp[u][v], p);
            dp[v][u] = max(dp[v][u], -p);
        }

        // Floyd Warshall
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                if(dp[i][k] == LLONG_MIN) continue;
                for(int j = 0; j < n; j++)
                {
                    if(dp[k][j] == LLONG_MIN) continue;
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp;
    };

    vector<vector<ll>> dp1, dp2, dp3;

    dp1 = f(edges1);
    if(dp1[0][0] >= req)
    {
        cout<<1<<endl;
        return;
    }

    dp2 = f(edges2);
    for(int k = 0; k < n; k++)
    {
        if(dp1[0][k] == LLONG_MIN || dp2[k][0] == LLONG_MIN) continue;
        if(dp1[0][k] + dp2[k][0] >= req)
        {
            cout<<2<<endl;
            return;
        }
    }

    dp3 = f(edges3);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dp1[0][i] == LLONG_MIN || dp2[i][j] == LLONG_MIN || dp3[j][0] == LLONG_MIN)
            {
                continue;
            }
            if(dp1[0][i] + dp2[i][j] + dp3[j][0] >= req)
            {
                cout<<3<<endl;
                return;
            }
        }
    }

    cout<<-1<<endl;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}