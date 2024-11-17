/**
 *    author: Saurav
 *    created: 2024.11.17 18:54:22
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
void dfs1(vector<vector<int> > &tree, int node, int par, vector<int> &v, set<int> &st){
    for(auto child : tree[node]){
        if(child == par) continue;
        dfs1(tree, child, node, v, st);

        if(v[child] == 1){
            v[node] = 1;
        }
    }

    if(st.find(node) != st.end()){
        v[node] = 1;
    }

    return;
}

void dfs3(vector<vector<int> > &tree, int node, int par, vector<int> &v , vector<int> &v2){
    int cnt = 0;
    // debug(node);

    for(auto child : tree[node]){
        if(child == par) continue;
        if(v[child] == 1){
            cnt++;
        }
        // debug(cnt)

        dfs3(tree, child, node, v, v2);
    }

    if(cnt == 0){
        v2[node] = 1;
    }

    return;
}

bool dfs2(vector<vector<int> > &tree, int node, int par, vector<int> &v){
    int cnt = 0;
    // debug(node);

    for(auto child : tree[node]){
        if(child == par) continue;
        if(v[child] == 1){
            cnt++;
        }
        // debug(cnt);

        if(cnt > 1){
            return false;
        }

        if(!dfs2(tree, child, node, v)){
            return false;
        }

    }

    return true;
}
void solve(){
    int n;
    cin>>n;

    vector<vector<int> > tree(n+1, vector<int>());
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        set<int> st;
        for(int i = 0; i<k; i++){
            int x;
            cin>>x;
            st.insert(x);
        }

        vector<int> v(n+1, 0);

        dfs1(tree, 1, 0, v, st);

        print(v);

        vector<int> v2(n+1, 0);

        dfs3(tree, 1, 0, v, v2);

        print(v2);

        int startnode = -1;

        for(auto ele : st){
            if(v2[ele] == 1){
                startnode = ele;
                break;
            }
        }

        debug(startnode);

        if(startnode == -1){
            cout<<"NO"<<endl;
            continue;
        }

        v.clear();
        v.resize(n+1, 0);

        dfs1(tree, startnode, 0, v, st);

        print(v);

        if(dfs2(tree, startnode, 0, v)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
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

