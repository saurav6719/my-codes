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
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<vector<int> > v;
    if(a>0){
        v.push_back({2});
        a--;
    }
    else if(b>0){
        v.push_back({1});
        b--;
    }
    else if(c>0){
        v.push_back({0});
        c--;
    }
    int i  = 1;
    while(a>0 or b>0 or c>0){
        vector<int> xx = v.back();
        vector<int>next;
        for(auto ele : xx){
            if(ele == 0 and (a>0 or b>0 or c>0)){
                cout<<-1<<endl;
                return;
            }
            for(int k = 0; k<ele;k++){
                if(a>0){
                    next.push_back(2);
                    a--;
                    continue;
                }
                if(b>0){
                    next.push_back(1);
                    b--;
                    continue;
                }
                if(c>0){
                    next.push_back(0);
                    c--;
                    continue;
                }
                cout<<-1<<endl;return;
            }
        }
        v.push_back(next);
    }

    vector<int> last = v.back();
    for(auto ele : last){
        if(ele != 0){
            cout<<-1<<endl;
            return;
        }
    }

    cout<<v.size() - 1<<endl;
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

