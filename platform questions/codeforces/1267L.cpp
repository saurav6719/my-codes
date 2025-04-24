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
    int n,l,k;
    cin>>n>>l>>k;

    string str;
    cin>>str;

    sort(str.begin(),str.end());

    print(str);

    vector<string> ans(n);
    int curr = 0;
    int i = 0;

    while(true ){
        debug(i);
        
        if(curr == k-1) break;
        if(ans[k-1].size()==l) break;
        bool update = false;
        int currcopy = curr;
        char last = str[i + k-curr-1];
        debug(last);
        for(int j= curr; j<k; j++){
            debug(j);
            if(str[i] == last and update == false){
                curr = currcopy;
                update = true;
            }
            ans[currcopy].push_back(str[i]);
            currcopy++;
            i++;
            debug(ans[j].back());
            debug(curr);


        }
        debug(curr);
    }
    print2d(ans);

    if(ans[k-1].size() < l){
        while(ans[k-1].size() < l){
            ans[k-1].push_back(str[i]);
            i++;
        }
    }

    while(i<n*l){
        for(int j = 0; j<ans.size(); j++){
            while(ans[j].size() < l){
                ans[j].push_back(str[i]);
                i++;
            }
        }
    }

    print2d(ans);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
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

