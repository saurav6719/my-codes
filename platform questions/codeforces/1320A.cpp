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
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        maxi = max(maxi , input[i]);
    }
    
    vector<pair<int,int> > same;
    for(int i = 0; i<n; i++){
        same.push_back({input[i] + n-i , i});

    }

    


    sort(same.begin(), same.end());

    // for(int i = 0; i<n; i++){
    //     cout<<same[i].first<<" "<<same[i].second<<endl;
    // }


    vector<int> ans;

    int i = 0;
    while(i<n){
        int cnt = input[same[i].second];
        // debug(cnt);
        int j = i+1;
        while(j<n){
            if(same[j].first != same[j-1].first) {
                i = j;
                
                debug(cnt);
                break;
            }
            cnt += input[same[j].second];
            j++;
        }
        i = j;
        ans.push_back(cnt);
    }
    

    sort(ans.begin(), ans.end());
    cout<<max(ans[ans.size()-1], maxi);
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

