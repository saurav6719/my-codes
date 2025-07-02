#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int mod = 1e9+7;
int n,k;
ll A[200005];
void solve(){
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> A[i];
	string s; cin >> s;
	int sum = 0;
	for(int i=0; s[i]; i++){
		sum += s[i]-'0';
	}
	ll ans = 0;
	if(!sum){
		priority_queue<int,vector<int>,less<int>>pq;
		for(int i=1; i<n; i++) pq.push(A[i]);
		for(int i=1; i<=k; i++){
			ans += pq.top();
			pq.pop();
		}
	}
	else if(sum == k){
		priority_queue<int,vector<int>,less<int>>pq;
		for(int i=2; i<=n; i++) pq.push(A[i]);
		for(int i=1; i<=k; i++){
			ans += pq.top();
			pq.pop();
		}
	}
	else{
		if(s.back() == '0'){
			reverse(A+1,A+n+1);
			for(int i=0; s[i]; i++){
				if(s[i] == '1') s[i] = '0';
				else s[i] = '1';
			}
		}
		int d = 0;
		for(int i=0; s[i]; i++) if(s[i] == '0') d = i+1;
		assert(d);
		vector<pi>v;
		for(int i=1; i<=n; i++){
			v.emplace_back(pi(A[i],i));
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		set<int>st;
		ll tot = 0;
		for(int i=0; i<k; i++) tot += v[i].first;
		for(int i=0; i<k; i++) st.insert(v[i].second);
		
		for(int i=1; i<=d+1; i++){
			if(st.find(i) == st.end()){
				ans = tot;
				cout<<ans%mod<<'\n';
				return;
			}
		}
		ll mn = INT64_MAX;
		for(int i=1; i<=d+1; i++){
			if(A[i] < mn) mn = A[i];
		}
		ll ret = 0;
		for(int i=d+2; i<=n; i++){
			if(st.find(i) == st.end()) ret = max(ret,A[i]);
		}
		ans = tot - mn + ret;
	}
	cout<<ans%mod<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
}