//****************************Template Begins****************************//

// Header Files
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
// Header Files End

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define DIVYA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<=b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define allr1(v) (v).rbegin()+1,(v).rend()
#define sort0(v) sort(all(v))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define sz(x) (ll)x.size()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005
const ll mod = 1e9 + 7;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
//****************************Template Ends*******************************//
vector<vll>adj;
ll cnt;
vector<bool>vis;

void dfs(ll curr_node)
{
    vis[curr_node] = true;
    cnt++;
    for(auto x : adj[curr_node])
    {
        if(vis[x])continue;
        dfs(x);
    }
}

int main() {
    DIVYA;
    ll t, n, i, j, ans, temp, sum;
    string sans;
    t = 1;
    cin >> t;
    while (t--)
    {
        sans = "NO";
        ans = temp = sum = 0;
        cin >> n;
        adj.assign(n+1,{});
        vis.assign(n+1,false);
        cnt = 0;
        vll a(n+1,0),b(n+1,0);
        fo(i,1,n)
        {
            cin>>a[i];
        }
        fo(i,1,n)
        {
            cin>>b[i];
            adj[a[i]].pb(b[i]);
            adj[b[i]].pb(a[i]);
        }
        ll tot = 0;
        fo(i,1,n)
        {
            if(!vis[i])
            {
                cnt = 0;
                dfs(i);
                tot+=(cnt/2);
            }
        }

        // cout<<tot<<endl;
        // fo(i,1,tot)
        // {
        //     ans-=2*i;
        // }
        // for(i=n;i>=n-tot+1;i--)
        // {
        //     ans+=2*i;
        // }
        // cout<<ans<<"\n";

        int last = n-1;
        for(int i = 0; i<tot; i++){
            ans += 2*last;
            last-=2;
        }

        cout<<ans<<endl;
    }
    return 0;
}






