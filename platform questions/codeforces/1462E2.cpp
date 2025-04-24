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
#define pp pair<int,int>
using namespace std;

/* write core logic here */

long long nCr(int n, int r) {
    if(r > n || r < 0) return 0;  // Handle invalid cases
    if(r == 0 || r == n) return 1; // Handle edge cases
    r = min(r, n - r);  // nCr is symmetric, so this reduces the number of operations
    long long ans = 1;
    for(int i = 0; i < r; ++i) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

void solve(){
    int n,m,k;
    cin>>n;
    m=3; k=2;
    vector<int> input(n);
    map<int,int> mp;

    for(int i = 0; i<n; i++){
        cin>>input[i];
        mp[input[i]]++;
    }

    sort(input.begin(), input.end());
    print(input);
    int ans = 0; 
    set<int> visited;
    int pichla = -1;
    for(int i = 0; i<n; i++){

        int xx = lower_bound(input.begin(), input.end(), input[i]) - input.begin();
        int yy = upper_bound(input.begin(), input.end(), input[i] + k) - input.begin();
        debug(input[i]);
        debug(yy - xx);
        int zz = nCr(yy - xx - 1, m-1);
        if(input[i] != input[i-1] ) pichla = yy - xx - 1;

        if(i > 0 and input[i] == input[i-1]){
            zz = nCr(pichla - 1, m-1);
            pichla = pichla - 1;
        }
        
        debug(zz);
        ans += zz;
        debug(ans);
        visited.insert(input[i]);
    }

    cout << ans << endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}
