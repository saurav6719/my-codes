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
    int m;
    cin>>m;
    
    vector<int> v(30,0);
    while(m--){
        int type;
        cin>>type;
        int idx;
        cin>>idx;
        bool ans = true;
        if(type == 1){
            v[idx]++;
        }
        
        else{
            map<int,int> mp;
            for(int i = 0; i<30 ; i++){
                if(v[i] == 0) continue;
                mp[i] = v[i];
            }
            // for(auto ele : mp){
            //     cout<<ele.first<<" "<<ele.second<<" "<<endl;
            // }
            for(int i = 0; i<30; i++){
                // if(mp.count(0)) debug(mp[0]);
                // if(mp.count(1)) debug(mp[1]);
                // if(mp.count(2)) debug(mp[2]);
                // if(mp.count(3)) debug(mp[3]);

                if((1<<i) & idx){
                    if(mp.count(i) == 0){
                        //debug(i);
                        ans = false;
                        break;
                    }
                    mp[i]--; 
                }
                if(mp[i] > 1){
                    mp[i+1] += (mp[i]/2); 
                    mp[i] = 0;
                }
            }
            if(!ans){
                cout<<"NO"<<endl;
                continue;
            }
            cout<<"YES"<<endl;
        }
        
    }
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

