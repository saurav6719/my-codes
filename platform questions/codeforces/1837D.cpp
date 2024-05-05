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
    int co = 0;
    int cc = 0;
    vector<int> ans;
    for(int i = 0; i<n; i++){
        if(str[i] == '('){
            if(cc){
                cc--;
                ans.push_back(2);
            }
            else {
                co++;
                ans.push_back(1);
            }
        }
        else{
            if(co){
                co--;
                ans.push_back(1);
            }
            else{
                cc++;
                ans.push_back(2);
            }
        }
    }

    if(co or cc){
        cout<<-1<<endl;
        return;
    }
    
    vector<int> copy = ans;
    sort(copy.begin(), copy.end());
    int cnt = 1;
    for(int i = 1; i<ans.size(); i++){
        if(ans[i] != ans[0]){
            cnt++;
            break;
        }
    }
    bool palat  = false;
    if(copy[0] == 2) palat = true;

    cout<<cnt<<endl;
    for(int i = 0; i<n; i++){
        if(palat) cout<<1<<" ";
        else{
            cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
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

