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
int numberOfTerms(int a, int d, int l) {
    if(a>l) return 0;
    if(a==l) return 1;
    return max (0ll, (l - a) / d + 1);
}
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> input(n);
    for(int i =0; i<n; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end());
    print(input);
    vector<int> prf(n);
   
    prf[0] = input[0];
    for(int i = 1; i<n; i++){
        prf[i] = prf[i-1] + input[i];
    }
    print(prf);
    int totalday = 0;
    int packets = 0;
    int i = n-1;
    while(i>=0){
        prf[i] += totalday * (i+1);
        debug(prf[i]);
        int currdays = numberOfTerms(prf[i], i+1, x);
        debug(currdays);
        packets += (currdays * (i+1));
        debug(packets);
        
        totalday += currdays;
        debug(totalday);
        i--;
    }
 
    cout<<packets<<endl;
 
 
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