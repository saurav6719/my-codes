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
const int MOD = 1e9 + 7;

// Function to calculate power in modular arithmetic
long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1; // y = y/2
        x = (x * x) % MOD;
    }
    return res;
}
bool poss(int mid , map<int,int> &mp, int w){
    vector<pair<int,int> > v(30);
    for(int i = 0; i<30 ;i++){
        if(w & (1<<i)){
            v[i].first = 1;
        }
        else v[i].first = 0;
    }

    

    for(int i = 0; i<30; i++){
        if(mp.count((1<<i))){
            v[i].second = mp[(1<<i)];
        }
    }


    // for(auto ele : v){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }
    int i = 29;
    while(v[i].first == 0)i--;
    //debug(i);
    int cnt= 0;
    int extra = 0;
    int maxi = v[i].second;
    //debug(maxi);
    cnt += v[i].second;
    
    v[i].second -= maxi;
    //debug(v[i].second);
    //debug(cnt);
    i--;
    //debug(i);
    while(i>=0){
        if(v[i].first == 1){
            debug(i);
            v[i].second -= maxi;
            debug(v[i].second);
        }
        i--;
    }
    bool check= false;
    int minus = 0;
    for(int i = 30; i>=0; i--){
        if(v[i].second < 0) {
            //debug(i);
            check = true;
            //debug(power(2,i));
            int pow = power(2,i);
            //debug(v[i].second);
            minus = minus + (pow * abs(v[i].second));
            //debug(minus);
        }

        if(check and v[i].second >0){
            //debug(minus);
            int quan = minus / (1<<i);
            if(quan > v[i].second) quan = v[i].second;
            //debug(quan);
            v[i].second -= quan;
            minus -= quan * (1<<i);
            //debug(minus);
        }
    }

    //debug(check);

    for(int i = 0; i<30; i++){
        if(v[i].second > 0){
            extra += ((1<<i) * v[i].second);
        }
    }
    //debug(extra);
    cnt += extra / w;
    //debug(cnt);
    if(extra % w != 0) cnt++;
    return cnt <= mid;
}

void solve(){
    int n;
    cin>>n;
    int w ;
    cin>>w;
    vector<int> input(n);
    map<int,int> mp;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        mp[input[i]]++;
    }

    sort(input.begin(), input.end());
    // for(auto ele: mp){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }
    int lo = 0;
    int hi = 1e6;
    int res = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(poss(mid,mp, w)){
            res = mid;
            
            hi = mid -1;
        }
        else lo = mid + 1;
    }
    cout<<res<<endl;
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

