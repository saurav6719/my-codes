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
bool cmp(pair<int,int> & a, pair<int,int> &b){
  if(a.first == b.first) return a.second < b.second;
  return a.first<b.first;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int, int > > input(n);
    for(int i = 0; i<n; i++){
      cin>>input[i].first;
      input[i].second = i;
    }

    sort(input.begin(), input.end(), cmp);

    vector<int> bought(n,0);
    int i = 0;
    while(k>m){
      int ele = input[i].second;
      debug(ele);
      bought[ele] = m;
      i++;
      k-=m;
    }

    vector<int> costdaywise(n);

    for(int i = 0;i<n; i++){
      int day = input[i].second;
      costdaywise[day]  = input[i].first;
    }

    print(costdaywise);

    bought[input[i].second] = k;
    
    print(bought);

    vector<int> sfx(n+1);
    sfx[0] = 0;
    for(int i = 1; i<=n; i++){
      sfx[i] = sfx[i-1]+bought[i-1];
    }

    print(sfx);

    int ans = 0;
    for(int i = 0; i<n; i++){
      int cost = 0;
      debug(i);
      debug(bought[i]);
      debug(sfx[i-1]);
      debug(costdaywise[i]);
      cost += (bought[i] * costdaywise[i]);
      
      cost += (bought[i] * sfx[i]);
      debug(cost);
      ans += cost;
    }

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

