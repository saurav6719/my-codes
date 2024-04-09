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

int n;
string str;

bool poss(int i, set<int> zeroidx, set<int> &firstidx){
    debug(i);
    while(zeroidx.size() > 0){
        int ff = *zeroidx.begin();
        debug(ff);
        
        int checked = ff+i-1;
        debug(checked);
        if(checked >= n) return false;
        zeroidx.erase(ff);
        for(int j = ff+1; j<=checked; j++){
            if(j>=n) break;
            if(zeroidx.count(j)){
                debug(j);
                zeroidx.erase(j);
            }
            else{
                //debug(j);
                zeroidx.insert(j);
            }
        }
        if(checked >=n and zeroidx.size() == 0) return true;
        if(checked >=n and zeroidx.size() > 0) return false;

    }
    return true;
}
void solve(){
    
    cin>>n;
    
    cin>>str;
    int ans = 1;
    set<int> zeroidx;
    set<int> firstidx;
    for(int i = 0; i<n; i++){
        if(str[i] == '0'){
            zeroidx.insert(i);
        }
        else{
            firstidx.insert(i);
        }
    }
    for(int i = n ; i>1; i--){
        if(poss(i,zeroidx, firstidx)) {
            //cout<<"gfwsgse"<<i<<endl;
            ans = i;
            break;
        }
    }
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

