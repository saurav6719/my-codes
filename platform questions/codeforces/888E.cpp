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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

int mod;
/* write core logic here */
void f(vector<int> &input, vector<int> &mp, int idx, int sum){
    if(idx == input.size()) {
        mp.push_back(sum % mod);
        return;
    }

    //take

    f(input, mp, idx+1, sum+input[idx]);

    // not take 

    f(input, mp, idx+1, sum);
}

void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    mod = m;
    vector<int> input(n);
    for(int i = 0;i<n; i++){
        cin>>input[i];
    }

    vector<int> left;
    vector<int> right;

    for(int i = 0; i<n/2; i++){
        left.push_back(input[i]);
    }
    for(int i = n/2; i<n; i++){
        right.push_back(input[i]);
    }

    vector<int>  lefty;
    vector<int>  righty;

    f(left, lefty, 0, 0);
    f(right, righty, 0,0);

    sort(righty.begin(), righty.end());
    int ans = 0;

    print(righty);
    print(lefty);

    for(auto ele : lefty){
        int xx = ele;
        int req = mod - xx - 1;
        debug(xx);
        debug(req);

        int lb = lower_bound(righty.begin(), righty.end(), req) - righty.begin();

        if(lb == righty.size()) lb--;

        if(righty[lb] > req) lb--;


        if(lb < 0) continue;
        debug(righty[lb]);

        ans = max(ans , xx + righty[lb]);

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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

