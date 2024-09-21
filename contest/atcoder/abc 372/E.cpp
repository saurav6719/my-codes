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

/* write core logic here */

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int find(vector<int> &parent, int x){
    return parent[x] == x ? x : find(parent, parent[x]);
}

void Union(vector<int> &parent,vector<int> &rank, int a, int b, vector<ordered_set> &vec, vector<int> &size){
    a = find(parent,a);
    b = find(parent,b);

    if(a==b) return;

    debug(a);
    debug(b);
    if(size[a] >= size[b]){
        debug(a);
        debug(b);
        size[a]+= size[b];
        parent[b] = a;
        vector<int> v;
        for(auto ele : vec[a]){
            v.push_back(ele);
        }
        for(auto ele : vec[b]){
            v.push_back(ele);
        }

        vec[a].clear();

        sort(v.begin(), v.end(), greater<int> ());
        int xx = v.size();
        for(int i = 0; i< min (10ll, xx); i++){
            vec[a].insert(v[i]);
        }
    }
    else{
        size[b]+= size[a];
        parent[a] = b;
        vector<int> v;
        for(auto ele : vec[a]){
            v.push_back(ele);
        }
        for(auto ele : vec[b]){
            v.push_back(ele);
        }

        vec[b].clear();

        sort(v.begin(), v.end(), greater<int> ());
        int xx = v.size();
        for(int i = 0; i< min (10ll, xx); i++){
            vec[b].insert(v[i]);
        }

    }
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);

    vector<int> size(n+1,1);


    vector<ordered_set> vec(n+5);

    for(int i = 1; i<=n; i++){
        vec[i].insert(i);
    }


    for(int i = 0; i<=n ; i++){
        parent[i] = i;
    }

    while(m--){
        int type;
        cin>>type;

        if(type == 1){
            debug(type);
            int u,v;
            cin>>u>>v;

            Union(parent, rank , u, v, vec, size);

        }

        // for(auto ele : vec[1]){
        //     cout<<ele<<" ";
        // }
        // cout<<endl;

        else{
            int v,k;
            cin>>v>>k;
            int xx = find(parent, v);
            debug(xx);
            ordered_set &oset = vec[xx];

            // for(auto ele : oset){
            //     cout<<ele<<" ";
            // }
            // cout<<endl;
            
            if(k > 0 && k <= oset.size()){
                auto it = oset.find_by_order(oset.size() - k);
                debug(*it);
                cout<<*it<<endl;
                continue;
            }
            else{
                cout<<-1<<endl;
                continue;
            }
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

