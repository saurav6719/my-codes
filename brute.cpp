/**
 *    author: Saurav
 *    created: 2024.12.27 01:55:47
 **/

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
set<int> total;
set<int> odd;
set<int> even;
bool poss = true;
void dfs(vector<vector<int> > &tree, int node, int par , vector<int> &values){
    int parentval = values[node];
    for(auto child : tree[node]){
        if(child == par) continue;

        int plusone = parentval + 1;
        if(total.count(plusone)){
            values[child] = plusone;
            total.erase(plusone);
            if(plusone%2 == 0){
                even.erase(plusone);
            }else{
                odd.erase(plusone);
            }

            dfs(tree,child,node,values);
        }
        else{
            if(parentval % 2 == 0){
                if(even.empty()){
                    poss = false;
                    return;
                }
                int val = *even.begin();
                if(abs(val - parentval) == 2){
                    if(even.size() < 2){
                        poss = false;
                        return;
                    }
                    else{
                        val = *(++even.begin());
                    }
                }
                if(abs(val - parentval) == 2){
                    if(even.size() < 3){
                        poss = false;
                        return;
                    }
                    else{
                        val = *(++(++even.begin()));
                    }
                }
                values[child] = val;
                even.erase(val);
                total.erase(val);
                dfs(tree,child,node,values);

            }
            else{
                if(odd.empty()){
                    poss = false;
                    return;
                }
                int val = *odd.begin();

                if(node == 4){
                    debug(val);
                    debug(parentval);
                }
                if(abs(val - parentval) == 2){
                    if(odd.size() < 2){
                        poss = false;
                        return;
                    }
                    else{
                        val = *(++odd.begin());
                    }
                }
                if(abs(val - parentval) == 2){
                    if(odd.size() < 3){
                        poss = false;
                        return;
                    }
                    else{
                        val = *(++(++odd.begin()));
                    }
                }
                values[child] = val;
                odd.erase(val);
                total.erase(val);
                dfs(tree,child,node,values);
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    total.clear();
    odd.clear();
    even.clear();

    for(int i = 1; i<=2*n; i++){
        total.insert(i);
        if(i%2 == 0){
            even.insert(i);
        }else{
            odd.insert(i);
        }
    }

    vector<int> values(n+1);
    values[0] = 0;
    values[1] = 1;

    total.erase(1); 
    odd.erase(1);


    dfs(tree,1,0,values);

    if(!poss){
        cout<<-1<<endl;
        return;
    }

    for(int i = 1; i<=n; i++){
        cout<<values[i]<<" ";
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

