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
    map<int,int> mp;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        mp[ele]++;
    }
    vector<int> stor;
    for(auto ele : mp){
        stor.push_back(ele.second);
    }

    sort(stor.begin(), stor.end(), greater<int> ());

    print(stor);

    int ans = 0;
    int maxi = stor[0];
    ans += stor[0];
    for(int i = 1; i<stor.size(); i++){
        if(maxi <= 0) break;
        if(stor[i] >= maxi){   
            ans += maxi - 1;
            maxi--;
        }
        else{
            ans += stor[i];
            maxi = stor[i];
        }
        
    }

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

