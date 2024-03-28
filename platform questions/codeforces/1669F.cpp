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
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0 ;i<n; i++){
        cin>>input[i];
    }
    vector<int> prf(n);
    vector<int> suf(n);
    prf[0] = input[0];
    suf[n-1] = input[n-1];
    for(int i = 1; i<n; i++){
        prf[i] = prf[i-1] + input[i];
    }
    for(int i = n-2; i>=0;i--){
        suf[i] = suf[i+1] + input[i];
    }
    print(prf);
    print(suf);
    int ans1 = 0;
    int ans2 =0;
    int i = 0; 
    int j = n-1;
    while(i<j){
        if(prf[i] == suf[j]){
            ans1 = i+1;
            ans2 = n-j;
            i++;
            j--;
        }
        else if(prf[i] < suf[j]){
            i++;
        }
        else j--;
        
    }
    cout<<(ans1+ans2)<<endl;
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

