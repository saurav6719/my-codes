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
    int h;
    cin>>h;
    int n;
    cin>>n;
    set<int> st;
    vector<int> v;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
        st.insert(ele);
    }
    st.insert(0);
    reverse(v.begin(), v.end());
    int last = 2;
    map<int,int> mp;
    mp[0] = 0;
    mp[1] = 0;
    mp[2] = 0;
    for(int i = 0; i<n; i++){
        int ele = v[i];
        if(mp.count(ele)) {
            mp[ele+1] = min(((st.count(ele)) ? (1 + mp[ele]) : (mp[ele])) , ((st.count(ele-1)) ? (mp[ele-1]) : (1+ mp[ele-1])));
            last = ele+1;
            debug(ele+1);
            debug(mp[ele+1]);
            continue;
        }
        int prev = ele-1;
        int secondprev = ele-2;

        if(mp.count(prev) == 0){
            mp[prev] = mp[last];
            mp[secondprev] = mp[last];
        }

        mp[ele] = min(st.count(ele-1) ? 1+mp[ele-1] : mp[ele-1] , st.count(ele-2) ? mp[ele-2] : 1+ mp[ele-2]);
        mp[ele+1] =  min(st.count(ele) ? 1 + mp[ele] : mp[ele] , st.count(ele-1) ? mp[ele-1] : 1+ mp[ele-1]);
        last = ele+1;

        printmap(mp);
    }

    cout<<mp[h]<<endl;


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

