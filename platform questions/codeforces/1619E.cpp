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

using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<
    T,                        // Use just 'T' (int in this case) for values
    null_type,                // No mapped type, because we want set-like behavior
    less_equal<T>,                  // Less-than comparator for sorting
    rb_tree_tag,              // Use a red-black tree for ordering
    tree_order_statistics_node_update // Enables order statistics
>;

template <typename T>
using ordered_set = tree<
    T,                        // Use 'T' for value type (int, double, etc.)
    null_type,                // No mapped type, because we want set-like behavior
    less<T>,                  // Less-than comparator for sorting
    rb_tree_tag,              // Use a red-black tree to maintain the order
    tree_order_statistics_node_update // Enables order statistics
>;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    ordered_multiset<int>  oset;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        input[i] = x;
        oset.insert(x);
    }

    map<int,int> mp;
    for(int i= 0; i<n; i++){
        mp[input[i]]++;
    }

    printmap(mp);

    vector<int> sum(n+5,0);

    sum[0] = 0;
    sum[1] = 0;
    for(int i = 2; i<=n; i++){
        sum[i] = sum[i-1]+mp[i-1]*(i-1);
    }

    map<int,int> extrafreq;
    ordered_set<int> extra;
    for(auto ele : mp){
        if(ele.second > 1){
            extrafreq.insert({ele.first, ele.second - 1});
            extra.insert(ele.first);
        }
    }

    vector<int> dp(n+5, 0);



    vector<int> ans(n+1, -1);
    ans[0] = mp[0];
    dp[0] = 0;

    debug(mp[5]);

    for(int i = 1; i<=n; i++){
        int currans =0;
        currans += mp[i];
        currans += dp[i-1];
        if(mp[i-1] > 0){
            debug(i);
            dp[i] = dp[i-1];
        }
        else{
            int chote = extra.order_of_key(i-1);
            debug(i);
            debug(chote);
            if(chote == 0) break;
            else{
                int xx = *extra.find_by_order(chote- 1);
                debug(xx);
                extrafreq[xx]--;
                if(extrafreq[xx] == 0){ 
                    extra.erase(xx);
                }
                currans += i-1 -xx;
                dp[i] = dp[i-1] + i-1 -xx;
            }
        }

        ans[i] = currans;


    }
    print(dp);
    for(int i = 0; i<=n; i++){
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

