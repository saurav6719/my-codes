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
    string str;
    cin>>str;
    vector<int> zero(n);
    if(str[0] == '0') zero[0] = 1;
    else zero[0] = 0;
    vector<int> one(n);
    for(int i = 1; i<n; i++){
        zero[i] = zero[i-1];
        if(str[i] == '0') zero[i]++;
    }
    if(str[n-1] == '1') one[n-1] = 1;
    else one[n-1] = 0;
    for(int i = n-2 ;i >=0; i--){
        one[i] = one[i+1];
        if(str[i] == '1') one[i]++;
    }
    print(zero);
    print(one);
    
    int a = n/2 + (n%2) - 1;
    debug(a);
    while(a>=-1){
        debug(a);
        int leftre = a+1;
        debug(leftre);
        int rightre = n-leftre;
        debug(rightre);
        if(a==-1){
            if(one[0] >= n/2 + n%2) break;
        }
        if( a>=0 and zero[a] >= leftre/2 + leftre%2 and one[a+1] >= rightre/2 + rightre%2) break; 
        a--;
    }
    
    debug(a);
    if(a == n/2 + (n%2) - 1){
        int leftre = a;
        int rightre = n-leftre;
        if(zero[a-1] >= leftre/2 + leftre%2 and one[a] >= rightre/2 + rightre%2) a= a-1;
    }
   

    int b = n/2 + (n%2) - 1;
    debug(b);
    while(b<n-1){
        debug(b);
        int leftre = b+1;
        debug(leftre);
        int rightre = n-leftre;
        debug(rightre);
        if(zero[b] >= leftre/2 + leftre%2 and one[b+1] >= rightre/2 + rightre%2) break; 
        b++;
    }
    if(b==n-1){
        int leftre = n;
        int rightre = 0;
        if(zero[b] >= leftre/2 + leftre %2) b =  n-1;
        else b = INT_MAX;
    }
    
    debug(b);
    int ans;
    if(a==-2) {
        ans = b+1;
        cout<<ans<<endl;
        return;
    }

    debug(a);
    debug(b);

    int mid = n/2 + n%2;
    int ff = a+1;
    int ss = b+1;

    debug(mid);
    debug(ff);
    debug(ss);
    if(abs(abs(mid-ff) - abs(ss-mid)) <= 1){
        if(n&1) ans = min(ff,ss);
        else ans = max(ff,ss);
        cout<<ans<<endl;
        return;
    }
    if(abs(mid-ff) <= abs(ss-mid)) ans = ff;
    else ans = ss;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

