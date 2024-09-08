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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;


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

template <class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    map<int,int> mp1;
    map<int,int> mp2;

    for(auto ele : a){
        mp1[ele]++;
    }

    for(auto ele : b){
        mp2[ele]++;
    }

    for(auto ele : mp1){
        if(ele.second != mp2[ele.first]){
            cout<<"NO"<<endl;
            return;
        }
    }

    map<int,set<int> > mpa;
    for(int i = 0; i<n; i++){
        mpa[a[i]].insert(i);
    }

    map<int,set<int> > mpb;
    for(int i = 0; i<n; i++){
        mpb[b[i]].insert(i);
    }

    oset<int>st;


    int ans = 0;

    for(int i = 0; i<n; i++){
        int ele = a[i];
        
        int index = *(mpb[ele].begin());
        debug(index);
        st.insert(index);

        mpb[ele].erase(mpb[ele].begin());
        int diff = index - i;
        debug(diff);
        int xx =  (st.order_of_key(index));
        debug(xx);
        
        int greater = st.size()-1 - xx;
        debug(greater);
        diff += greater;
        ans += diff;

    }

    debug(ans);
    if(ans & 1){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;

    



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

