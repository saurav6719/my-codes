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
#define MOD 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, int mod = MOD) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return C;
}

vector<vector<int>> matrixExponentiate(vector<vector<int>> base, int exp, int mod = MOD) {
    int n = base.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    
    // Initialize result as the identity matrix
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = matrixMultiply(result, base, mod);
            exp--;
            continue;
        }
        base = matrixMultiply(base, base, mod);
        exp /= 2;
    }

    return result;
}
void solve(){
    int n;
    cin>>n;

    if(n==0 or n==1) {
        cout<<n;
        return;
    }
    vector<vector<int> > base(2, vector<int> (2));
    base[0][0] = 1;
    base[0][1] = 0;
    base[1][0] = 0;
    base[1][1] = 0;
    vector<vector<int> > v(2, vector<int> (2));
    v[0][0] = 1;
    v[0][1] = 1;
    v[1][0] = 1;
    v[1][1] = 0;
    print2d(v);

    vector<vector<int> > res = matrixExponentiate(v, (n-1));
    print2d(res);
    res = matrixMultiply(res, base);
    print2d(res);
    int ans = 0;
    for(auto ele : res[0]){
        //only the first row represent F(n);
        ans += ele;
        ans %= MOD;
    }

    cout<<ans;
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

