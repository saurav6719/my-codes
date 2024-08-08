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

std::vector<int> computeSPF(int maxN) {
    // Step 1: Initialize the SPF array with the number itself
    std::vector<int> spf(maxN + 1);
    for (int i = 2; i <= maxN; ++i) {
        spf[i] = i;
    }

    // Step 2: Use a modified Sieve of Eratosthenes to fill the SPF array
    for (int i = 2; i * i <= maxN; ++i) {
        if (spf[i] == i) {  // i is a prime number
            for (int j = i * i; j <= maxN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}
std::vector<int> getPrimeFactors(int n, const std::vector<int>& spf) {
    std::vector<int> factors;

    while (n != 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }

    return factors;
}



void solve(vector<int> &sieve){
    int l,r;
    cin>>l>>r;

    if(__gcd(l, r) != 1){
        cout<<0<<endl;
        return;
    }

    if(r-l == 1){
        cout<<-1<<endl;
        return;
    }
    int diff = r-l;

    vector<int> primes = getPrimeFactors(diff, sieve);
    int ans = INT_MAX;
    for(auto ele : primes){
        int yy = l / ele;
        int rem = l % ele;

        if(rem == 0){
            cout<<0<<endl;
            return;
        }

        int a = ele *( yy+1);
        debug(a);

        ans = min(ans, a-l);
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
    // t = 1;

    vector<int> sieve = computeSPF(1e7 + 5);
    for(int i = 1; i<=t; i++){
        solve(sieve);
    }
return 0;
}

