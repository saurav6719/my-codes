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

    int i = n-2;
    int ans = INT_MAX;
    while(i>=0){
        vector<int> v;
        vector<char> op;
        for(int j = 0; j<i; j++){
            v.push_back(str[j] - '0');
        }
        v.push_back((str[i] - '0') * 10 + (str[i+1]- '0'));
        for(int j = i+2; j<n; j++){
            v.push_back(str[j] - '0');
        }

        //print(v);

        for(int j = 0; j<v.size(); j++){
            if(v[j] == 0){
                cout<<0<<endl;
                return;
            }
        }
        

        for(int j = 1; j<v.size(); j++){
            if(v[j] >= 2 and v[j-1] >= 2){
                op.push_back('+');
            }
            else{
                v[j] = v[j] * v[j-1];
                v[j-1] = 0;
            }
        }
        //print(op);
        int cnt = 0;
        
        

        for(int j = 0; j<v.size(); j++){
            cnt += v[j];
        }
        

        ans = min(ans, cnt);
        i--;
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

