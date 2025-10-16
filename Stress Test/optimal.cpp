/*
Author : MadhavCoding
*/

#define _Alignof alignof

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

void solve()
{
    ll n; cin>>n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    // for(auto i : v) cout<<i<<" ";
    // cout<<endl;

    ll q; cin>>q;
    vector<pair<pll, ll>> query(q);
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        cin>>l>>r;
        l--; r--;
        query[i] = {{l, r}, i};
    }
    
    sort(query.begin(), query.end(), [](pair<pll, ll> a, pair<pll, ll> b){
        return a.first.second < b.first.second;
    });

    vector<ll> res(q);

    map<ll, ll> last, diff, endpt;
    ordered_set last_index, end_point;

    int j = 0;
    for(auto p : query)
    {
        ll l = p.first.first, r = p.first.second, ind = p.second;

        // cout<<"l r ind : "<<l<<" "<<r<<" "<<ind<<endl;

        while(j <= r)
        {
            if(last.find(v[j]) == last.end())
            {
                last[v[j]] = j;
                last_index.insert(last[v[j]]);
            }
            else if(diff.find(v[j]) == diff.end())
            {
                diff[v[j]] = j - last[v[j]];

                last_index.erase(last[v[j]]);
                last[v[j]] = j;
                last_index.insert(last[v[j]]);
            }
            else
            {
                ll cur_diff = j - last[v[j]];
                if(diff[v[j]] != cur_diff)
                {
                    end_point.erase(endpt[v[j]]);
                    endpt[v[j]] = j;
                    end_point.insert(endpt[v[j]]);
                }
                diff[v[j]] = cur_diff;
                
                last_index.erase(last[v[j]]);
                last[v[j]] = j;
                last_index.insert(last[v[j]]);
            }
            j++;
        }

        ll siz = last_index.size();
        ll temp = last_index.order_of_key(l);
        ll distinct = siz - temp;
        // cout<<"distinct : "<<distinct<<endl;

        siz = end_point.size();
        temp = end_point.order_of_key(l);
        ll curr_end = siz - temp;
        // cout<<"curr_end : "<<curr_end<<endl;

        ll curr_ans = distinct + 1;
        if(curr_end < distinct) curr_ans--;

        res[ind] = curr_ans;
    }

    for(auto i : res) cout<<i<<endl;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}