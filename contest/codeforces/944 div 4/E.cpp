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
    int n,k,q;
    cin>>n>>k>>q;
    
    vector<int> v;
    v.push_back(0);
    vector<int> time;
    

    for(int i = 0; i<k; i++){
        int ele ;
        cin>>ele;
        v.push_back(ele);
    }

    time.push_back(0);

    for(int i = 0; i<k ;i++){
        int ele ;
        cin>>ele;
        time.push_back(ele);
    }


    while(q--){
        int min;
        cin>>min;
        if(min == 0) {
            cout<<0<<" ";
            continue;
        }
        if(min == n){
            cout<<time[time.size() - 1]<<" ";
            continue;
        }

        int ans = 0;
        int xx = upper_bound(v.begin(), v.end(), min) - v.begin();
        xx--;
        ans += time[xx];

        int extra = min - v[xx];
        int speed = time[xx+1] - time[xx];
        int dist = v[xx+1] - v[xx];

        ans += (speed * extra) / dist;
        cout<<ans<<" ";
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

