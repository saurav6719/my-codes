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
    int k;
    cin>>k;
    vector<int> input(n);
    map<int,int> mp;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        mp[input[i]]++;
    }
    for(auto ele : mp){
        cout<<ele.first<<" "<<ele.second<<endl;
    }

    while(k>0){
        if(mp.size() <= 1) break;
        auto it = mp.begin();
        pair<int,int> pp = *it;
        mp.erase(it);
        auto it2 = mp.begin();
        pair<int,int> pp2 = *it2;
        mp.erase(it2);
        auto diff = pp2.first - pp.first;
        auto multi = pp.second;
        int resf = pp.second + pp2.second;
        diff *= multi;
        debug(diff);
        if(k>=diff){
            // debug(pp2.first);
            // debug(pp2.second);
            k-= diff;
            if(resf>0) mp.insert({pp2.first, resf});
        }
        
        else{
            //debug(pp.first);

            //debug(pp.second);

            if(k>0) mp.insert({pp.first +k, k});
            if(pp.second-k > 0)mp.insert({pp.first, pp.second-k});
            if(mp.count(pp2.first)){
                mp[pp2.first] += pp2.second;
            }
            else mp.insert({pp2.first, pp2.second});            
            k = 0;
            break;
        }

    }
    debug(k);
    if(k>0){
        auto it = mp.begin();
        mp.erase(it);
        pair<int,int> pp = *it;
        int xx = pp.first;
        int yy = pp.second;
        
        xx += k/yy;
        mp.insert({xx,yy});
    }


    cout<<endl;
    for(auto ele : mp){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    auto it = mp.begin();
    pair<int,int> pp = *it;
    int ans = 0;
    int xx = pp.second;
    int full = n-xx;
    ans += (full * pp.first);
    ans += pp.first;
    ans += (pp.first - 1) * (xx-1);
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

