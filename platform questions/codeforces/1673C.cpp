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

bool isPalindrome(int number) {
    int originalNumber = number;
    int reversedNumber = 0;
    int remainder;

    while (number != 0) {
        remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number /= 10;
    }

    return originalNumber == reversedNumber;
}


void solve(){
    
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
    vector<int> v;
    for(int i = 1; i<= 4e4; i++){
        if(isPalindrome(i)){
            v.push_back(i);
        }
    }
    int n;
    vector<int> dp(4e4 + 5, 0);
        
    dp[0] = 1;
    for(int i = 0; i<v.size(); i++){
        for(int j = 1; j <= 4e4; j++){
            if(j- v[i] >= 0){
                dp[j] = (dp[j] % mod + dp[j-v[i]] % mod) % mod;
                
            }
        }
    }
    while(t--){
        
        cin>>n;
        cout<<dp[n]<<endl;
       
    }
return 0;
}

