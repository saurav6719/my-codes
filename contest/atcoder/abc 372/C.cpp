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
    int n,q;
    cin>>n>>q;
    string str;
    cin>>str;
    set<int> curr;
    for(int i = 0; i+2<n; i++){
        if(str[i] == 'A' and str[i+1] == 'B' and str[i+2] == 'C'){
            curr.insert(i);
        }
    }


    while(q--){
        int x;
        cin>>x;
        x--;
        char c;
        cin >> c;

        if(str[x] == c) {
            cout<<curr.size()<<endl;
            continue;
        }
        str[x] = c;

        if(curr.count(x)){
            curr.erase(x);
        }

        if(curr.count(x-1)){
            curr.erase(x-1);
        }

        if(curr.count(x-2)){
            curr.erase(x-2);
        }

        if(x+2 < n and str[x] == 'A' and str[x+1] == 'B' and str[x+2] == 'C'){
            curr.insert(x);
        }

        if(x-2 >= 0 and str[x-2] == 'A' and str[x-1] == 'B' and str[x] == 'C'){
            curr.insert(x-2);
        }
        if(x-1 >= 0 and str[x-1] == 'A' and str[x] == 'B' and x+1 < n and str[x+1] == 'C'){
            curr.insert(x-1);
        }

        cout<<curr.size()<<endl;
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

