/**
 *    author: Saurav
 *    created: 2024.11.07 16:28:33
 **/

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

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    std::less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;


/* write core logic here */




void solve(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> input(n);
    for(auto &x : input){
        cin>>x;
    }

    ordered_set<pair<int,int>> os ;
    for(int i = 0 ; i < n ; i++){
        os.insert({input[i],i}) ;
    }

    while(q--){
        char type;
        cin>>type;
        if(type == '!'){
            int k,x ;
            cin>>k>>x;
            --k;
            os.erase({input[k],k}) ;
            input[k] = x ;
            os.insert({input[k],k}) ;

        }
        else{
            int a,b;
            cin>>a>>b;
            int xx = os.order_of_key({b+1,0}) - os.order_of_key({a,0}) ;
            cout<<xx<<endl ;
        }
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

