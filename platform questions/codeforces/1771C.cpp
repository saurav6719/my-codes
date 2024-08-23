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

std::vector<int> generatePrimes(int MAXSQRTN) {
    std::vector<bool> isPrime(MAXSQRTN + 1, true); // Initialize all numbers as prime
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int i = 2; i * i <= MAXSQRTN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXSQRTN; j += i) {
                isPrime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= MAXSQRTN; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

set<int> pf(int x, vector<int> &primes){
    set<int> v;
    for(int i =0; i<primes.size(); i++){
        if ((primes[i] * primes[i]) > x) break; // No need to check beyond sqrt(x)
        while(x % primes[i] == 0){
            x /= primes[i];
            v.insert(primes[i]);
        }
    }
    if(x > 1) v.insert(x);
    return v;
}

void solve(vector<int> &primes){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    set<int> st;

    for(int i = 0; i<n; i++){
        int ele = input[i];
        set<int> v = pf(ele, primes);
        debug(ele);

        for(auto ele2 : v){
            if(st.count(ele2)){
                cout<<"YES"<<endl;
                return;
            }
            st.insert(ele2);
        }
    }

    cout<<"NO"<<endl;


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
    const int MAXSQRTN = 31622; // sqrt(1e9)
    std::vector<int> primes = generatePrimes(MAXSQRTN);
    // t = 1;
    while(t--){
        solve(primes);
    }
return 0;
}