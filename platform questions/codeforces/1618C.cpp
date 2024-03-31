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

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int gcd1 = input[0];
    for(int i = 2; i<n; i+=2){
        gcd1 = gcd(gcd1, input[i]);
    }
    int gcd2 = input[1];
    for(int i = 3; i<n; i+=2){
        gcd2 = gcd(gcd2, input[i]);
    }
    bool can1 = true;
    bool can2 = true;

    
    for(int i = 0; i<n; i+=2){
        if(input[i] % gcd2 == 0){
            can1 = false;
            break;
        }
    }
    
    
    for(int i = 1; i<n; i+=2){
        if(input[i] % gcd1 == 0){
            can2 = false;
            break;
        }
    }
    
    if(gcd1 == gcd2){
        can1= false;
        can2 = false;
    }


    if(!can1 and !can2){
        cout<<0<<endl;
    }
    else {
        if(can1) cout<<gcd2<<endl;
        else cout<<gcd1<<endl;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

