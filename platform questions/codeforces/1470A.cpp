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
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> number(n);
    for(int i = 0; i<n; i++){
        cin>>number[i];
    }   
    map<int,int> mp;
    vector<int> gifts(m);
    for(int i = 0; i<m; i++){
        cin>>gifts[i];
        mp[gifts[i]]++;
    }
    print(gifts);
    print(number);
    for(int i = 0; i<n; i++){
        int toput = gifts[number[i]-1];
        debug(toput);
        mp[toput]++;
    }

    int cnt = 0;
    int cost = 0;
    for(auto ele : mp){
        debug(ele.first);
        debug(ele.second);
        cnt+= min(n,ele.second);
        debug(n);
        int xx = ele.first;
        int yy = min(n, ele.second);
        int zz = xx * yy;
        cost += zz;
        debug(cost);
        n-= min(n,ele.second);
        if(n<=0) break;
    }
    cout<<cost<<endl;


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

