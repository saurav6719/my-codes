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

string f (string str){
    int n = str.size();
    print(str);
    debug(n);
    debug(str[0]);
    if(n==0) return "";
    if(n==1) {
        // cout<<"YES";
        string ans = "";
        ans += str[0];
        return ans;
    }
    map<char,int> mp;
    for(auto ele : str){
        mp[ele]++;
    }

    if(mp.size() == 2){
        auto ele = *mp.begin();
        auto ele2 = *mp.rbegin();
        debug(ele2.second);
        if(ele.second == 1){
            string ans = "";
            for(int i = 0; i< (ele2.second / 2 + ele2.second % 2); i++){
                ans += ele2.first;
            }
            ans += ele.first;
            for(int i = 0; i<ele2.second/2; i++){
                ans+= ele2.first;
                
            }
            print(ans);
            return ans;
        }
    }

    int i = 0;

    string rest = "";
    if(i+1 < n) rest = str.substr(i+1);
    rest += str[i];
    return rest;
}
void solve(){
    string str;
    cin>>str;

    sort(str.begin(), str.end());

    string left = "";
    string right = "";
    int n = str.size();

    int i = 0;
    while(i<n-1 and str[i] == str[i+1]){
        left += str[i];
        right += str[i+1];
        i+=2;
    }

    print(left);
    print(right);

    reverse(right.begin(), right.end());

    if(i==n){
        cout<<left+right<<endl;
        return;
    }
    debug(i);
    print(str.substr(i));
    string rest = f(str.substr(i));
    print(rest);
    
    cout<<left+rest+right<<endl;
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

