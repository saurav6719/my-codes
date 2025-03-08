/**
 *    author: Saurav
 *    created: 2025.03.08 10:34:16
 *    We stop at Candidate Master in 2025
 **/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
					cout << "vect--" << #v << " = [ "; \
					for (int i = 0; i < v.size(); i++) { \
						cout << v[i] << " "; \
					} \
					cout << " ]" << endl; \
				} while(0)
#define print2d(v) do { \
					cout << "vect-- starts" << endl; \
					for (int i = 0; i < v.size(); i++) { \
						cout << "[" << " "; \
						for (int j = 0; j < v[i].size(); j++) { \
							cout << v[i][j] << " "; \
						} \
						cout << "]" << endl; \
					} \
					cout << "vect-- ends" << endl; \
				} while(0)
#define printmap(m) do { \
					cout << "map-- starts" << endl; \
					for (auto it = m.begin(); it != m.end(); ++it) { \
						cout << it->first << " -> " << it->second << endl; \
					} \
					cout << "map-- ends" << endl; \
				} while(0)

#define printpp(v) do { \
					cout << "vect--" << " = [ "; \
					for (int i = 0; i < v.size(); i++) { \
						cout << "(" << v[i].first << ", " << v[i].second << ") "; \
					} \
					cout << " ]" << endl; \
				} while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int query(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	cout.flush();
	int x;
	cin>>x;
	return x;
}
void printans(int i,int j, int k){
	cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
	cout.flush();
}
void solve(){
	int n;
	cin>>n;

	int lo = 1;
	int hi = n;
	int k = -1;
	int total = query(1,n);
	map<int,int> mp;

	mp[n] = total;

	while(lo <= hi){
		int mid = lo + (hi - lo)/2;
		int x;
		if(mp.find(mid) != mp.end()){
			x = mp[mid];
		}
		else x = query(1, mid);
		mp[mid] = x;
		if(x == total){
			k = mid;
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}

	int y1 = query(1,k);
	int y2 = query(1, k-1);
	int diff = y1 - y2;

	int j = k- diff;

	int y3 = query(1,j);
	int ix;

	lo = 1;
	hi = n;

	int res = -1;

	while(lo <= hi){
		int mid = lo + (hi - lo) /2;
		int sum = (mid) * (mid + 1) / 2;
		if(sum == y3){
			res = mid;
			break;
		}
		else if(sum < y3){
			lo = mid + 1;
		}
		else{
			hi = mid - 1;
		}
	}

	ix = j - (res + 1);

	printans(ix,j,k);
	cout<<endl;

	
}
/* logic ends */

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("Error.txt" , "w" , stderr);
	#endif
	int t;
	cin>>t;
	//t = 1;
	while(t--){
		solve();
	}
return 0;
}

