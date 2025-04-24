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
    map<int,int> mp;
    set<int> yzero;
    set<int> yone;

    set<pp> coord;

    vector<pp> input;



    for(int i = 0; i<n; i++){

        int xx,yy;
        cin>>xx>>yy;

        if(yy==0){
            yzero.insert(xx);
        }
        if(yy==1){
            yone.insert(xx);
        }

        coord.insert({xx,yy});
        input.push_back({xx,yy});
    }

    int ans = 0;
    for(auto ele : input){
        int xx = ele.first;
        int yy = ele.second;
        if(coord.count({xx, (yy^1)})){
            if(yy==0){
                ans += yzero.size() - 1;
            }
            else ans+= yone.size() - 1;
        }
    }


    for(auto ele : input){
        if(ele.second == 0) continue;
        int xx = ele.first;
        if(yzero.count(xx-1) and yzero.count(xx+1)){
            ans++;
        }
    }
   for(auto ele : input){
        if(ele.second == 1) continue;
        int xx = ele.first;
        if(yone.count(xx-1) and yone.count(xx+1)){
            ans++;
        }
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

