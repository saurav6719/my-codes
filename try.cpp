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
int round(int n){
	if(n&1) return n/2 + 1;
	return n/2;
}
void solve(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	int one = 0;
	for(int i = 0; i<n; i++){
		if(str[i] == '1') one ++;
	}
	int zero = n - one;
	debug(zero);
	debug(round(zero));
	debug(round(one));
	vector<int> cnt0(n,0);
	vector<int> cnt1(n,0);
	if(str[0] == '0') cnt0[0] = 1;
	else cnt1[0] = 1;
	for(int i = 1; i<n; i++){
		if(str[i] == '0'){
			cnt0[i] = cnt0[i-1] + 1;
			cnt1[i] = cnt1[i-1];
		}
		else{
			cnt0[i] = cnt0[i-1];
			cnt1[i] = cnt1[i-1] + 1;
		}
	}

	reverse(cnt1.begin(), cnt1.end());

	// print(cnt0);
	// print(cnt1);
	int ans ;
	int ans2;
	int mid;
	if(n%2 == 0) mid = n/2 -1;
	else mid = n/2;
	int mid2 = mid;
	
	while(mid >0){
		if(cnt0[mid] >= round(zero) and cnt1[mid] >= round(one)){
			ans = mid;
			break;
		}
		mid--;
	}
	debug(ans);
	while(mid2 <n){
		if(cnt0[mid2] >= round(zero) and cnt1[mid2] >= round(one)){
			ans2 = mid2;
			break;
		}
		mid2++;
	}
	//debug(ans2);
	int xx = abs(n/2-mid2);
	//debug(xx);
	int yy = abs(n/2 - mid);
	//debug(yy);
	if(xx<yy){
		ans = ans2;
	}
	cout<<ans+1<<endl;



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

