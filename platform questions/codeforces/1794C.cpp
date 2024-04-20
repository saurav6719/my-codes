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
int poss(vector<int> &input, int i){
    int lo = i;
    int hi = input.size() - 1;
    int res = -1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(input[mid] >= mid-i+1) {
            res = mid - i;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    reverse(input.begin(), input.end());
    vector<int> ans;
    //debug(poss(input,1));
    for(int i = 0;i<n; i++){
        ans.push_back(poss(input,i)+1);
    }
    reverse(ans.begin(), ans.end());
    for(auto ele:ans){
        cout<<ele<<" ";
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

