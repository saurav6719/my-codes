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
    int w;
    cin>>w;
    vector<int> input(n);
    map<int,int> mp;
    map<int,int> mp2;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        mp[input[i]]++;
        mp2[input[i]]++;
    }

    print(input);
    for(auto ele: mp){
        if(ele.first * 2 <= w){
            mp[ele.first * 2] += ele.second / 2;
            mp[ele.first] = ele.second % 2;
        }
    }

    for(auto ele : mp){
        cout<<ele.first<<" "<<ele.second<<endl;
    }

    auto highest = mp.rbegin();
    auto high = *highest;
    int hh = high.first;
    debug(hh);
    int cnt = high.second;
    int maxextra = w-hh;
    int extra = (w-hh) * cnt;
    int sum  = 0;
    bool plus = false;
    for(auto ele : mp2){
        if(ele.first <hh and ele.first > maxextra){
            plus = true;
        }
    }


    debug(plus);
    if(plus) {
        cout<<cnt+1<<endl;
        return;
    }

    for(auto ele:mp){
        if(ele.first < hh and ele.second > 0){
            sum += ele.first;
        }
    }
    debug(sum);
    if(sum<=extra) {
        cout<<cnt<<endl;
        return;
    }

    cout<<cnt+1<<endl;
    
    
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

