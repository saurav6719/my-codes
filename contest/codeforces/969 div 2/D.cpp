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
    vector<int> indegree(n+1);

    for(int i = 1; i<=n-1; i++){
        int u,v;
        cin>>u>>v;
        indegree[u]++;
        indegree[v]++;
    }

    int questionleaf = 0;
    int zeroleaf = 0;
    int oneleaf =0;

    string str;
    cin>>str;

    str = 'a' + str;

    for(int i = 2; i<=n; i++){
        if(indegree[i] > 1) continue;
        if(str[i] == '1'){
            oneleaf++;
        }
        else if(str[i] == '0'){
            zeroleaf++;
        }

        else questionleaf++;
    }
    debug(zeroleaf);
    debug(questionleaf);
    debug(oneleaf);

    if(str[1] == '1'){
        int ans = zeroleaf + ((questionleaf) / 2 + (questionleaf) % 2);
        cout<<ans<<endl;
        return;
    }

    if(str[1] == '0'){
        int ans = oneleaf + ((questionleaf) / 2 + (questionleaf) % 2);
        cout<<ans<<endl;
        return;
    }

    // now root is not known to us 

    if(zeroleaf > oneleaf){
        // cout<<"YES"<<endl;
        int ans = zeroleaf + (questionleaf/2);
        cout<<ans<<endl;
        return;
    }

    if(oneleaf > zeroleaf){
        int ans = oneleaf + (questionleaf/2);
        cout<<ans<<endl;
        return;
    }

    // now root is unknown and oneleaf == zeroleaf 

    int cntfaltu = 0;
    for(int i = 2; i<=n; i++){
        if(indegree[i] == 1)continue;
        if(str[i] == '?') cntfaltu++;
    }

    if(cntfaltu % 2== 0){
        //iris kaa chance aaya first 
        int ans = zeroleaf + (questionleaf/2);
        cout<<ans<<endl;
        return;
    }
    else{
        //dora kaa chance aaya first 
        int ans = zeroleaf + (questionleaf/2) + (questionleaf%2);
        cout<<ans<<endl;
        return;
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
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

