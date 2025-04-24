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
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */

const int MOD = 1e9 + 7;

// Function to calculate power in modular arithmetic
long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1; // y = y/2
        x = (x * x) % MOD;
    }
    return res;
}

// Function to calculate factorial in modular arithmetic
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res = (res * i) % MOD;
    return res;
}

// Function to calculate nCr in modular arithmetic
long long nCr(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    long long numerator = factorial(n);
    long long denominator = (factorial(r) * factorial(n - r)) % MOD;
    return (numerator * power(denominator, MOD - 2)) % MOD;
}

int power_mod(int base, int exponent) {
    int result = 1;
    base %= mod; // Handle cases where base >= mod
    while (exponent > 0) {
        if (exponent & 1) { // If exponent is odd
            result = (__int128(result) * base) % mod;
        }
        base = (__int128(base) * base) % mod;
        exponent >>= 1; // Equivalent to exponent // 2
    }
    return result;
}

int mod_inverse(int b){
    // Since mod is prime, inverse of b is b^(mod-2) % mod
    return power_mod(b, mod - 2);
}


void dfs1(vector<vector<int> > &tree, int node, int par, vector<int> &subtreesize){
    int ans = 1;
    for(auto child : tree[node]){
        if(child == par) continue;
        dfs1(tree, child, node, subtreesize);
        ans += subtreesize[child];
    }
    subtreesize[node] = ans;
}

void dfs(vector<vector<int> > &tree, int node, int par, vector<vector<int> > & d2subtree, vector<int> &subtreesize){

    vector<int> ans;
    for(auto child : tree[node]){
        if(child == par) continue;
        dfs(tree, child, node, d2subtree, subtreesize);
        ans.push_back(subtreesize[child]);
    }

    sort(ans.begin(), ans.end());
    d2subtree[node] = ans;

}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int> > tree(n+5, vector<int> ());

    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<vector<int> > d2subtree(n+5, vector<int> ()); 

    vector<int> subtreesizes(n+5, 0);

    dfs1(tree, 1, 0, subtreesizes);

    dfs(tree, 1, 0, d2subtree, subtreesizes);

    // print2d(d2subtree);

    vector<int> sums(n+5, 0);

    for(int i= 1; i<=n; i++){
        int curr = 0;
        for(int j = 0; j<d2subtree[i].size(); j++){
            curr += d2subtree[i][j];  
        }
        sums[i] = curr;
    }

    print(sums);

    for(int i = 2; i<=n; i++){
        int toadd = n-1 - sums[i];
        d2subtree[i].push_back(toadd);
    }

    for(int i = 1; i<=n; i++){
        sort(d2subtree[i].begin(), d2subtree[i].end());
    }

    print2d(d2subtree);


    if(k==1 or k==3){
        cout<<1<<endl;
        return;
    }

    if(k==2){

        int a = 0;
        for(int i = 1; i<=n; i++){

            if(d2subtree[i].size() == 0) continue;

            vector<int> &v = d2subtree[i];

            sort(v.begin(), v.end());

            vector<int> prf(v.size(), 0);

            prf[0] = v[0];

            for(int j = 1; j<v.size(); j++){
                prf[j] = prf[j-1] + v[j];
            }

            int totalsum = prf.back();

            for(int j = 0; j<v.size()-1; j++){
                int aa = prf[j];
                int bb = totalsum - prf[j];
                a += (v[j] %mod  * bb %mod) %mod;
                a %= mod;
            }

            for(int j = 0; j<v.size(); j++){
                int xx = v[j];
                xx %= mod;
                a += xx;
                a %= mod;
            }
        }

        debug(a);
        int b = n * (n-1);
        b/=2;
        b %= mod;

        b = mod_inverse(b);

        a *= b;
        a %= mod;
        cout<<a<<endl;

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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

