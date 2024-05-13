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
    vector<int> breaks;
    breaks.push_back(0);

    for(int i = 0; i<k; i++){
        int ele;
        cin>>ele;
        breaks.push_back(ele);
    }

    map<int,int> time;
    for(int i = 0; i<k; i++){
        int ff = breaks[i+1];
        int ss;
        cin>>ss;
        time[ff] = ss;
    }
    time[0] = 0;
    while(q--){
        int min;
        cin>>min;
        if(time.count(min)){
            cout<<time[min]<<" ";
            continue;
        }
        int xx = lower_bound(breaks.begin(), breaks.end(), min) - breaks.begin();
        xx--;
        int yy = upper_bound(breaks.begin(), breaks.end(), min) - breaks.begin();
        //debug(xx);
        //debug(yy);
        int gap = breaks[yy] - breaks[xx];
        //debug(gap);
        int aa = time[breaks[xx]];
        //debug(aa);
        int bb = time[breaks[yy]];
        //debug(bb);
        double res = bb-aa;
        //debug(res);
        res /= gap;
        //debug(res);
        double req = min - breaks[xx];
        //debug(breaks[xx]);
        //debug(req);
        //debug(req);
        double ans = 0;
        ans = aa;
        ans += (req * res);
        std::cout << std::fixed << std::setprecision(0) <<floor(ans)<< " ";
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

