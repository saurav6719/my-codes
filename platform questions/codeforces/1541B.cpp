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
int f(int i, int ele){
    if(i<ele and ele<=2*i){
        return 2*ele;
    }
    if(i<ele and ele > 2*i){
        return ele;
    }
    if(i>= ele){
        int quo = 2*i/ele;
        quo++;
        return quo*ele;
    }
}


void solve(){
    int n;
    cin>>n;
    vector<int> input(n+1);
    for(int i = 1;i<=n; i++){
        cin>>input[i];
    }
    print(input);
    vector<int> ans(n+1);
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        
        int ele = input[i];
        debug(ele);
        debug(i);
        int start = f(i,ele);
        debug(start);
        for(int j = start - i; j<=n; j+= ele){
            debug(j);
            if(input[i] * input[j] == i+j) cnt++;
        }
        
    }

    
    cout<<cnt<<endl;
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

