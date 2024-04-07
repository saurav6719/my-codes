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
    int n,m;
    cin>>n>>m;
    priority_queue<int> pq;
    vector<int> input(m);
    for(int i = 0; i<m; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end());
    pq.push(n-input[m-1] + input[0] -1);
    for(int i = 1; i<m; i++){
        int diff = input[i] - input[i-1] - 1;
        pq.push(diff);
    }
    int saved = 0;
    int itr = 0;
    while(!pq.empty()){
        int ele = pq.top();
        //debug(ele);
        pq.pop();
        ele -= (itr*4);
        ele = max(ele, 0ll);
        debug(ele);
        if(ele > 0){
            if(ele != 1) saved += ele - 1;
            else saved++;
            itr++;
        }
    }
    cout<<n-saved<<endl;
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

