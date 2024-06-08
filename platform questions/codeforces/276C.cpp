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
    int q;
    cin>>n>>q;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> input_copy = input;
    sort(input_copy.begin(), input_copy.end(), greater<int> ());

    vector<int> arr(n+5, 0);
    vector<pair<int,int> > queries;
    while(q--){
        int l;
        int r;
        cin>>l>>r;
        queries.push_back({l,r});
        arr[l]++;
        arr[r+1]--;
    }

    for(int i = 1; i<n+5; i++){
        arr[i] += arr[i-1];
    }

    sort(arr.begin(), arr.end(), greater<int> ());
    int ans  =0;
    for(int i = 0; i<n; i++){
        ans += (input_copy[i] * arr[i]);
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

