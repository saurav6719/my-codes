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
vector<int> dp(5000001);

vector<bool> is_prime(5000001, true);
set<int> primes;

void sieve(int n) {
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false; // Mark all multiples of i as non-prime
            }
        }
    }

    // Collect primes in a separate list
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.insert(i);
        }
    }
}
void solve(){
	int a;
	int b;
	cin>>a>>b;
	cout<<dp[a]- dp[b]<<endl;
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
	sieve(5000000);
	
	for(int i = 0; i<= 5000000; i++){
		if(i==0) {
			dp[0] = 0 ;
			continue;
		}
		if(i==1) dp[i] = 0;
		if(i==2) dp[i] = 1;
		if(i==3) dp[i] = 1;

		if(primes.count(i)){
			dp[i] = 1;
			continue;
		}

		for(auto ele : primes){
			if(i % ele == 0){
				dp[i] = dp[i/ele] + 1;
				break;
			}
		}
	}


	for(int i = 1; i<=5000000; i++){
		dp[i] += dp[i-1];
	}

	while(t--){
		solve();
	}
return 0;
}

