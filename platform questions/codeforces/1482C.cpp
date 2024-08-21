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
    int n,m;
    cin>>n>>m;
    vector<vector<int> > input;

    for(int i = 0; i<m; i++){
        int ele;
        cin>>ele;
        vector<int> v(ele);
        for(int j= 0; j<ele; j++){
            cin>>v[j];
        }
        input.push_back(v);
    }

    print2d(input);

    map<int,int> mp;

    vector<int> ans(m, -1);

    for(int i= 0; i<m; i++){
        if(input[i].size() == 1){
            ans[i] = input[i][0];
            mp[input[i][0]]++;
        }
    }

    printmap(mp);

    for(int i = 0; i<m; i++){
        if(ans[i] != -1) continue;
        debug(i);
        for(auto ele : input[i]){
            // debug(ele);
            if(mp[ele] < (m/2 + m%2)){
                // debug(ele);
                debug(ele);
                ans[i] = ele;
                debug(ans[i]);
                mp[ele]++;
                break;
            }
        }
    }



    for(auto ele : mp){
        if(ele.second > (m/2 + m%2)){
            debug(ele.first);
            cout<<"NO"<<endl;
            return;
        }
    }

    for(auto ele : ans){
        if(ele == -1){
            cout<<"NO"<<endl;
            return;
        }
    }


    cout<<"YES"<<endl;
    for(int i = 0; i<m; i++){
        cout<<ans[i]<<" ";
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

