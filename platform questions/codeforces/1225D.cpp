/**
 *    author: Saurav
 *    created: 2024.10.17 17:34:21
 **/

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
std::pair<int, int> hash_vector(const std::vector<int>& v) {
    int hash1 = 0xcbf29ce484222325ULL; // FNV-1a 64-bit offset basis
    int hash2 = 0x84222325cbf29ce4ULL; // Different offset basis
    const int32_t fnv_prime = 0x100000001b3ULL; // FNV-1a 64-bit prime

    for (int x : v) {
        // First hash function (FNV-1a)
        hash1 ^= static_cast<int>(x);
        hash1 *= fnv_prime;

        // Second hash function with different constants
        hash2 ^= static_cast<int>(x) + 0x9e3779b97f4a7c15ULL;
        hash2 *= fnv_prime;
    }

    return {hash1, hash2};
}

std::vector<int> prime_factorization(int x) {
    std::vector<int> factors;

    // Handle negative numbers
    if (x < 0) {
        factors.push_back(-1);
        x = -x;
    }

    // Handle 0 and 1
    if (x == 0 || x == 1) {
        // factors.push_back(x);
        return factors;
    }

    // Divide out factors of 2
    while (x % 2 == 0) {
        factors.push_back(2);
        x /= 2;
    }

    // Check for odd factors up to sqrt(x)
    for (int i = 3; i <= std::sqrt(x); i += 2) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }

    // If x is a prime number greater than 2
    if (x > 2) {
        factors.push_back(x);
    }

    // The factors are already in ascending order
    return factors;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    map<pp , int> mp;

    int ans = 0;

    for(int i = 0; i<n; i++){
        int ele = v[i];
        vector<int> hai = prime_factorization(ele);
        map<int,int> haimap;
        for(auto ele : hai){
            haimap[ele] ++;
        }

        vector<int> chahiye;

        debug(ele);
        print(hai);

        for(auto ele : haimap){
            int cnt = ele.second;
            if(cnt % k == 0) continue;
            int need = k - (cnt % k);

            for(int j= 1; j<=need; j++){
                chahiye.push_back(ele.first);
            }
        }
        print(chahiye);

        pp chahiyehash = hash_vector(chahiye);

        ans += mp[chahiyehash];

        vector<int> extrahai;
        for(auto ele : haimap){
            int cnt = ele.second;
            if(cnt % k == 0) continue;
            int extra = cnt % k;
            for(int j=1; j<=extra; j++){
                extrahai.push_back(ele.first);
            }
        }
        mp[hash_vector(extrahai)] ++;
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

