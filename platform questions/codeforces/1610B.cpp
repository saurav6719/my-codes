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
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    int a = 0;
    int b = n-1;
    while(input[a] == input[b]){
        a++;
        b--;
    }
    // debug(a);
    // debug(b);
    if(a>=b){
        cout<<"YES"<<endl;
        return;
    }
    int ff = input[a];
    debug(ff);
    int ss = input[b];
    debug(ss);

    int a1 = a;
    int b1 = b;
    int cnt = 0;
    while(a<=b and cnt < n+5){
        if(input[a] != input[b] and input[a] == ff){
            //cout<<"JHVDS"<<endl;
            a++;
            continue;
        }
        if(input[a] != input[b] and input[b] == ff){
            //cout<<"JHVDadfaS"<<endl;
            b--;
            continue;
        }
        if(input[a] == input[b]){
            //cout<<"JHVDSsdnqj"<<endl;
            a++;
            b--;
            continue;
        }
        cnt++;
    }

    if(a>=b){
        cout<<"YES"<<endl;
        return;
    }
    debug(a1);
    debug(b1);
    int cnt2 = 0;
    while(a1<=b1 and cnt2 < n+5){
        if(input[a1] != input[b1] and input[a1] == ss){
            a1++;
            continue;
        } 
        if(input[a1] != input[b1] and input[b1] == ss){
            b1--;
            continue;
        }  
        if(input[a1] == input[b1]){
            a1++;
            b1--;
            continue;
        }  
        cnt2++;
    }

    if(a1>=b1){
        cout<<"YES"<<endl;
        return;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

