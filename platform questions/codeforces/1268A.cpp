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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
vector<int> ans;
int dp[200005][2];
vector<int> curr;

bool f(string &str, int idx, bool smaller, int k){
    debug(idx);
    
    debug(smaller);
    if(idx == str.size()){
        return true;
    }
    if(idx - k >=0){
        curr[idx] = curr[idx-k];
        debug(curr[idx]);
        if(smaller == false and (curr[idx] + '0') < (str[idx])) {
            // cout<<"YES"<<endl;
            debug(curr[idx] - '0');
            debug(str[idx]);
            return false;
        }
        else if(smaller == false and ((curr[idx] + '0') == (str[idx]))){
            // cout<<"YES"<<endl;
            bool xx = f(str, idx+1, smaller, k);
            if(xx) return true;
            else return false;
        }
        else{
            bool xx = f(str, idx+1, true, k);
            if(xx) return true;
            else return false;
        }
    }

    int loop;
    if(smaller){
        loop = 0;
    }
    else loop = str[idx] - '0';
    debug(loop);
    
    for(int i = loop; i<=9; i++){
        bool newsmaller;
        if(smaller) newsmaller = true;
        else if(i == str[idx] - '0') newsmaller = false;
        else newsmaller = true;
        curr[idx] = i;
        bool xx = f(str, idx+1, newsmaller, k);
        if(xx) return true;
    }

    return false;
}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    string str;
    cin>>str;
    curr.resize(n+5);


    f(str, 0, 0, k);
    print(curr);

    cout<<n<<endl;

    for(int i = 0; i<n; i++){
        cout<<curr[i];
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

