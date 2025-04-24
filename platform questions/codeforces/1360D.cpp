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

bool isPrime(int n) {
    if (n <= 1) return false; // 0 and 1 are not primes
    if (n <= 3) return true; // 2 and 3 are primes

    // Check if n is divisible by any number from 2 to sqrt(n)
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false; // n is divisible by i, so it's not a prime
    }

    return true; // If no divisor found, n is prime
}


void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> div;

    if(isPrime(n)){
        if(k>=n){
            cout<<1<<endl;
            return;
        }
        else {
            cout<<n<<endl;
            return;
        }
    }


    for(int i = 1; i*i<=n; i++ ){
        if(n%i == 0){
            div.push_back(i);
            if(i*i != n){
                div.push_back(n/i);
            }
        }   
    }

    sort(div.begin(), div.end());

    print(div);

    int x = upper_bound(div.begin(), div.end(), k)- div.begin();
    debug(x);

    x--;

    cout<<n/div[x]<<endl;


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

