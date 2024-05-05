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
    vector<int> input(n);
    vector<vector<int> >bits(31, vector<int> ());

    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        input[i] = ele;
        for(int j= 0; j<=30; j++){
            if((ele & (1<<j)) == 0){
                bits[j].push_back(i);
            }
        }
    }

    print(bits[0]);
    print(bits[1]);
    print(bits[2]);
    print(bits[3]);
    print(bits[4]);
    int q;
    cin>>q;
    while(q--){
        int l;
        int k;
        cin>>l;
        cin>>k;
        int res1 = -1;
        int res2 = n;
        int maxofk = -1;
        for(int i = 30 ; i>=0; i--){
            if((1<<i) & k){
                maxofk = i;
                break;
            }
        }
        // debug(res2);
        debug(maxofk);
        bool tobreak = false;
        for(int i = maxofk+1;i<=30; i++){
            if(input[l-1] &(1<<i)){
                int xx = lower_bound(bits[i].begin(), bits[i].end(), l-1) - bits[i].begin();
                if(xx == bits[i].size()){
                    tobreak = true;
                    break;
                }
                res1 = max(res1 , bits[i][xx]-1);
            }
        }
        debug(res1);
        if(tobreak) {
            cout<<n<<" ";
            continue;
        }
        for(int i = 0; i<=maxofk; i++){
            if((((((1<<i)&input[l-1]) == 0) & (((1<<i) & k) != 0)))){
                //debug(i);
                res2 = -1;
                break;
            }
            // debug(((1<<i) & input[l-1]));
            // debug(((1<<i) & k));
            if((((1<<i) & (input[l-1]))== 0) and (((1<<i) & k) == 0)){
                continue;
            }
            if((((1<<i) & k) == 0)) continue;
            int xx = lower_bound(bits[i].begin(), bits[i].end(), l-1) - bits[i].begin();
            if(xx == bits[i].size()){
                res2 = min(res2,n-1);
            }
            else res2 = min(res2 , bits[i][xx]-1);
            debug(i);
            debug(res2);
        }
        debug(res2);

        // debug(res1);
        // debug(res2);
        int ans = max(res1,res2);
        ans++;
        if(ans == 0) ans--;
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

