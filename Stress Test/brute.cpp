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

struct query
{
	ll l, r, x, ind;
};

bool cmp(query q1, query q2)
{
	return q1.r < q2.r;
}

class SegTree
{
	ll size;
	vector<ordered_set> sums;
	ordered_set NEUTRAL = {};

public:

	void init(ll n)
	{
		size = 1;
		while(size < n) size *= 2;

		sums.resize(2 * size - 1, NEUTRAL);
	}

	void set_x(ll i, ll v, ll x, ll lx, ll rx, ll& olval)
	{
		if(rx - lx == 1)
		{
			if(!sums[x].empty()) olval = *sums[x].begin();
			sums[x].clear();
			sums[x].insert(v);
			return;
		}

		ll m = lx + (rx - lx) / 2;

		if(i < m) 
		{
			set_x(i, v, 2 * x + 1, lx, m, olval);
			if(olval != -1)
			{
				if(sums[2 * x + 2].find(olval) == sums[2 * x + 2].end())
				{
					sums[x].erase(olval);
				}
				else
				{
					olval = -1;
				}
			}
		}
		else 
		{
			set_x(i, v, 2 * x + 2, m, rx, olval);
			if(olval != -1)
			{
				if(sums[2 * x + 1].find(olval) == sums[2 * x + 1].end())
				{
					sums[x].erase(olval);
				}
				else
				{
					olval = -1;
				}
			}
		}

		sums[x].insert(v);
	}

	void set_x(ll i, ll v)
	{
		ll olval = -1;
		set_x(i, v, 0, 0, size, olval);
	}

	ll find_sum(ll l, ll r, ll x, ll lx, ll rx, ll xnum)
	{
		if(r <= lx || rx <= l) return 0;
		else if(l <= lx && r >= rx) 
        {
            ll sz = sums[x].size();
            ll temp = sums[x].order_of_key(xnum);
            return sz - temp;
        }

		ll m = lx + (rx - lx) / 2;

		ll s1 = find_sum(l, r, 2 * x + 1, lx, m, xnum);
		ll s2 = find_sum(l, r, 2 * x + 2, m, rx, xnum);

		return s1 + s2;
	}

	ll find_sum(ll l, ll r, ll xnum)
	{
		return find_sum(l, r, 0, 0, size, xnum);
	}
};

void solve()
{
	ll n; cin>>n;
	vector<ll> a(n);

	map<ll, ll> mpp;
	set<ll> colour;

	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
		colour.insert(a[i]);
	}

	ll d; cin>>d;
	vector<query> vec(d);
	for (int i = 0; i < d; i++)
	{
		ll l, r; cin>>l>>r;
		l--; r--;
		ll x; cin>>x;
		colour.insert(x);
		vec[i] = {l, r, x, i};
	}
	
	sort(vec.begin(), vec.end(), cmp);

	ll temp = 0;
	for(auto i : colour)
	{
		mpp[i] = temp++;
	}
	ll num = colour.size();

	SegTree st;
	st.init(num);

	vector<ll> res(d);

	int ind = 0;
	for(ll r = 0; r < n; r++)
	{
		st.set_x(mpp[a[r]], r);
		while(ind < d && r == vec[ind].r)
		{
			// cout<<"r : "<<r<<endl;
			// cout<<"query : "<<vec[ind].l<<" "<<vec[ind].r<<" "<<vec[ind].x<<" "<<vec[ind].ind<<endl;
			ll temp = st.find_sum(0, mpp[vec[ind].x] + 1, vec[ind].l);
			res[vec[ind].ind] = temp;
			ind++;
		}
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