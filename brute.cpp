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

void solve()
{
	
	ll n; cin>>n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	
	ll blocks = sqrtl(n) + 2;
	// cout<<"blocks : "<<blocks<<endl;
	vector<vector<query>> q(blocks, vector<query>());

	ll d; cin>>d;
	for (int i = 0; i < d; i++)
	{
		ll l, r; cin>>l>>r; 
		l--; r--;
		ll x; cin>>x;
		query qi = {l, r, x, i};
		q[l / blocks].push_back(qi);
	}
	
	for(auto &v : q) sort(v.begin(), v.end(), cmp);

	vector<ll> res(d);

	ll ckpt = blocks;
	for(auto v : q)
	{
		// cout<<"ckpt : "<<ckpt<<endl;

		ll last = ckpt;
		ordered_set os;
		map<ll, ll> freq;

		for(auto qi : v)
		{
			// cout<<"last : "<<last<<endl;
			// cout<<"qi "<<qi.l<<" "<<qi.r<<" "<<qi.x<<" "<<qi.ind<<endl;
			if(qi.r <= ckpt)
			{
				for(int i = qi.l; i <= qi.r; i++)
				{
					freq[a[i]]++;
					os.insert(a[i]);
				}

				res[qi.ind] = os.order_of_key(qi.x + 1);

				for(int i = qi.r; i >= qi.l; i--)
				{
					freq[a[i]]--;
					if(freq[a[i]] == 0)
					{
						os.erase(a[i]);
						freq.erase(a[i]);
					}
				}
			}

			else
			{
				for(int i = last + 1; i <= qi.r; i++)
				{
					freq[a[i]]++;
					os.insert(a[i]);
				}

				last = qi.r;

				for(int i = qi.l; i <= ckpt; i++)
				{
					freq[a[i]]++;
					os.insert(a[i]);
				}

				res[qi.ind] = os.order_of_key(qi.x + 1);

				for(int i = ckpt; i >= qi.l; i--)
				{
					freq[a[i]]--;
					if(freq[a[i]] == 0)
					{
						os.erase(a[i]);
						freq.erase(a[i]);
					}
				}
			}
		}

		ckpt += blocks;
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