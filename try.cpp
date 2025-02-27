/**
 *    author: Saurav
 *    created: 2025.02.27 02:10:42
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
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> input(n);
	for(int i = 0; i<n; i++){
		cin>>input[i];
	}

	vector<pp> inputcopy;
	for(int i =0 ; i<n; i++){
		inputcopy.push_back({input[i], i});
	}

	sort(inputcopy.begin(), inputcopy.end());

	vector<int> winloss(n, 0);
	int i = 0;

	multiset<pp> haraya;

	printpp(inputcopy);
	int haraycnt = 0;
	while(m>=0 and i < n){
		int req = inputcopy[i].first;
		int have = m;
		if(have >= req){
			winloss[inputcopy[i].second] = 1;
			haraya.insert({inputcopy[i].first, inputcopy[i].second});
			m-= req;
			haraycnt++;
		}
		else {
			if(!haraya.empty()){
				pp largest = * haraya.rbegin();
				int diff = req - largest.first;
				if(m>=diff){
					winloss[largest.second] = 0;
					winloss[inputcopy[i].second] = 1;
					haraycnt++;
				}
			}
			break;
		}
		i++;
	}
	debug(haraycnt);

	cout<<n-haraycnt + 1<<endl;
	return;


	int youwintotal = accumulate(winloss.begin(), winloss.end(), 0ll);

	vector<int> v;

	for(int i =0 ; i<n; i++){
		int curr =0 ;
		if(winloss[i] == 0) curr = 1;
		curr += i;
		v.push_back(curr);
	}

	sort(v.begin(), v.end(), greater<int> ());
	print(winloss);
	print(v);

	int rank = 1;
	for(int i = 0; i<v.size(); i++){
		if(v[i] > youwintotal) rank++;
	}

	cout<<rank<<endl;
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

