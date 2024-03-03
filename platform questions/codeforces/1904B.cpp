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
int f(vector<int> &prf, int x, vector<int>  &input1,int i){
    int st = upper_bound(input1.begin(), input1.end(), x) - input1.begin();
    if(st== prf.size()) return prf.size() -1;
    st--;
    //debug(st);
    if(st == i) return st;
    
    int ans = f(prf,prf[st], input1, st);
    //debug(ans);
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int> > input(n);
    vector<int> input1(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first;
        input[i].second = i;
        input1[i] = input[i].first;
    }
    sort(input.begin(), input.end());
    sort(input1.begin(), input1.end());
    vector<int> prf(n,0);
    
    
    prf[0] = input[0].first;
    for(int i = 1; i<n; i++){
        prf[i] += input[i].first;
        prf[i] += prf[i-1];
    }
    vector<int> ans(n);
    // print(prf);
    // print(input1);
    for(int i = 0; i<n; i++){
        ans[input[i].second] = f(prf,prf[i], input1, i);
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
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

