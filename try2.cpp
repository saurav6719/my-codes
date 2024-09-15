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

vector<vector<int> > dp;
int ans = 1e9;
    void f(vector<string> &words, string &target, int start, int cnt){
        
        if(start == target.size()) {
            ans = min(ans, cnt);
            return;
        }

        for(int i = start; i<target.size(); i++){
            int length = i-start+1;
            string prf = target.substr(start , length);
            print(prf);
            for(int j = 0; j<words.size(); j++){
                if(words[j].size() < length) continue;
                bool cantake = true;
                for(int k = 0; k<length; k++){
                    if(words[j][k] != prf[k]) {
                        cantake = false;
                        break;
                    }
                }
                if(cantake) {
                    debug(j);
                    (f(words, target , i+1, cnt+1));
                }
            }
        }
    }
    int minValidStrings(vector<string>& words, string target) {
        vector<int> visited(words.size(), 0);
        f(words, target , 0, 0);
        if(ans == 1e9) return -1;
        return ans;
    }
void solve(){

    vector<string> words = {"cbb","ddacebad","badadccbddacdedebddadcacabcaceedcecbddccedeca","adac","babceccd","acdecaec","dee","caeca"};
    string target = "dbabbaabcacdabbedaeebecbe";

    cout<<minValidStrings(words, target);
    
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

