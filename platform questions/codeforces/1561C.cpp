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
int highest(vector<int> &v){

    // if(v.size() == 1){
    //     return v[0]+1;
    // }
    // //print(v);
    int lo = 0;
    int hi = 1e15;
    int res = -1;
    while(lo<=hi){
        // debug(hi);
        // debug(lo);
        
        int mid = lo + (hi - lo)/2;
        //debug(mid);
        bool poss = true;
        int cnt = 1;
        //debug(v.size());
        for(int i = 0; i<v.size(); i++){
            int curr = mid + i;
            int ele = v[i];
            //debug(curr);
            // debug(ele);
            if(curr <= ele){
                cnt = 0;
                
                //debug(lo);
                //break;
            }
        }
        if(cnt){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    //debug(res);
    return res;
}

bool poss(int mid , vector<pair<int,int> > &v){
    for(int i = 0 ; i<v.size(); i++){
        int curr = v[i].first;
        if(mid < curr){
            return false;
        }
        mid += v[i].second;
    }
    return true;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > input(n, vector<int> ());
    for(int i = 0; i<n; i++){
        int k;
        cin>>k;
        for(int j = 0; j<k;j++){
            int ele ;
            cin>>ele;
            input[i].push_back(ele);
        }
    }
    //print(input[0]);
    vector<pair<int,int> > maximal;
    for(int i = 0; i<n; i++){
        maximal.push_back({highest(input[i]),input[i].size()});
    }

    sort(maximal.begin(), maximal.end());

    // for(auto ele: maximal){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }

    int lo = 0;
    int hi = 1e15;
    int res = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(poss(mid, maximal)){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid+1;
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

