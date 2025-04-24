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
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0;i<n; i++){
        cin>>input[i];
    }

    map<int,int> mp;
    for(int i = 0 ; i<n; i++){
        mp[input[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        set<pp> ab;
        int x;
        int y;
        cin>>x>>y;

        int xsquare = x * x;
        int d = (xsquare - (4 * y));
        int root = sqrt(d);
        if(root * root != d){
            cout<<0<<" ";
            continue;
        }

        int xplusroot = x + root;
        int xminusroot = x - root;

        if(xplusroot % 2 == 0 ){
            int a = xplusroot / 2;
            if(y % a == 0){
                int b = y/a;
                if(ab.count({a, b}) == 0 and ab.count({b,a}) == 0){
                    ab.insert({a,b});
                }
            }
        }

        if(xminusroot % 2 == 0 ){
            int a = xminusroot / 2;
            if(y % a == 0){
                int b = y/a;
                if(ab.count({a, b}) == 0 and ab.count({b,a}) == 0){
                    ab.insert({a,b});
                }
            }
        }

        int ans = 0;
        for(auto ele : ab){
            int a = ele.first;
            int b = ele.second;

            if(a == b){
                ans += ((mp[a] * (mp[a] - 1)) / 2);
            }

            else ans += (mp[a] * mp[b]);
        }

        cout<<ans<<" ";
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

