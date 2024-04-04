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

unsigned int nearestPowerOf2Smaller(unsigned int num) {
    // If num is already a power of 2, return the number itself
    if (num && !(num & (num - 1)))
        return num;
    
    // Right shift the number until it becomes 0
    while (num > 0) {
        num = num >> 1;
        if (num == 1) // If num becomes 1, return 1
            return 1;
    }
    
    // Initialize nearest with 2 and left shift it until it's greater than the original number
    unsigned int nearest = 2;
    while (nearest <= num)
        nearest = nearest << 1;
    
    // Right shift nearest once to get the nearest power of 2 smaller than the original number
    nearest = nearest >> 1;

    return nearest;
}
int f(int n, int k){
    //base case 
    if(n==1) return 2;
    if(n==0) return 1;
    int near = 
}
void solve(){
    int n,k;
    cin>>n>>k;
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

