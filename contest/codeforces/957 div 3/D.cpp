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
    int n,m,k;
    cin>>n>>m>>k;

    string str;
    cin>>str;
    

    vector<int> logs;
    logs.push_back(-1);
    for(int i = 0; i<n; i++){
        if(str[i] == 'L') logs.push_back(i);
    }

    logs.push_back(n);

    print(logs);



    int i = -1;
    int curr = 0;

    int cnt = 0;
    while(i<n and cnt<5){
        debug(i);
        if(i>=0  and i<n and str[i] == 'C') {
            cout<<"NO"<<endl;
            return;
        }
        if(i>=0  and i<n and str[i] == 'W'){
            curr++;
            if(curr > k){
                cout<<"NO"<<endl;
                return;
            }
            i++;
            continue;
        }

        int xx = lower_bound(logs.begin(), logs.end(), i+m) - logs.begin();
        debug(i+m);
        debug(xx);
        
        if(logs[xx] == i+m) {
            i = logs[xx];
            continue;
        }

        else{
            xx--;
            debug(xx);
            if(logs[xx] <= i) {
                i = i+m;
                if(str[i] == 'C'){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else{
                i = logs[xx];
            }
            
        }
        cnt++;
        
    }

    cout<<"YES"<<endl;
    return;
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

