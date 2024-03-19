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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans = 0;
	ans += a;
	int md = b%3;
	if(md+c <3 and md!= 0){
		cout<<-1<<endl;
		return;
	}
	int quo = b/3;
	ans += quo;
	int rem = md + c;
	debug(md);
	debug(rem);
	ans+= rem/3;
	if(rem%3!= 0) ans++;
	cout<<ans<<endl;
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

