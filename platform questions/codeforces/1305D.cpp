/**
 *    author: Saurav
 *    created: 2024.11.06 21:23:33
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

struct child{
    int nodenumber;
    int sizeofsubtree;

    bool operator < (const child &b) const{
        return sizeofsubtree > b.sizeofsubtree;
    }
};

int subtreesize(vector<vector<int> > &tree, int node, int par, vector<int> &ans){
    int size = 1;
    for(auto x : tree[node]){
        if(x != par){
            size += subtreesize(tree, x, node, ans);
        }
    }
    ans[node] = size;
    return size;
}


int query(int u, int v){
    cout<<"? "<<u<<" "<<v<<endl;
    cout.flush();
    int x;
    cin>>x;
    return x;
}

void dfsparent(vector<vector<int> > &tree, int node, int par, vector<int> &parent){
    parent[node] = par;
    for(auto x : tree[node]){
        if(x != par){
            dfsparent(tree, x, node, parent);
        }
    }
}

int lca (vector<vector<int> > &tree, int u, int v, vector<int> &parent){
    set<int> ancestors;
    while(true){
        ancestors.insert(u);
        if(u == 1){
            break ;
        }
        u = parent[u];
    }

    while(true){
        if(ancestors.count(v)){
            return v;
        }
        v = parent[v];
    }
}

void childrennsns(vector<vector<int> >&tree, int node, int par , vector<vector<int> > &ans){
    for(auto x : tree[node]){
        if(x != par){
            ans[node].push_back(x);
            childrennsns(tree, x, node, ans);
        }
    }
}

void printans(int r){
    cout<<"! "<<r<<endl;
    cout.flush();
}
void solve(){
    int n;
    cin>>n;

    vector<vector<int> > tree(n+1, vector<int> ());

    for(int i =0 ; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> subtreesizes(n+1);
    subtreesize(tree, 1, 0, subtreesizes);

    vector<vector<child> > children(n+1);

    vector<vector<int> > childrensss(n+1, vector<int> ());

    childrennsns(tree, 1, 0, childrensss);

    for(int i = 1; i<=n; i++){
        for(auto x : childrensss[i]){
            int size = subtreesizes[x];
            children[i].push_back({x, size});
        }
    }

    for(int i = 1; i<=n; i++){
        sort(children[i].begin(), children[i].end());
    }

    vector<int> parent(n+1);
    dfsparent(tree, 1, 0, parent);


    print(parent);



    int u = 1;


    for(auto ele : children[1]){
        debug(ele.nodenumber);
        debug(ele.sizeofsubtree);
    }

    while(true){
        if(children[u].empty()){
            break ;
        }

        if(children[u][0].sizeofsubtree == 1){
            break ;
        }
        debug(u);
        int v = children[u][0].nodenumber;
        debug(v);
        v = children[v][0].nodenumber;
        debug(v);
        // break;

        debug(u);
        debug(v);

        int correctlca = query(u, v);
        int mylca = lca(tree, u, v, parent);

        if(correctlca != mylca){
            u = correctlca;
            for(auto x : children[u]){
                if(x.nodenumber == v){
                    children[u].erase(children[u].begin());
                    break ;
                }
            }
        }
        else{
            children[u].erase(children[u].begin());
        }
    }

    vector<int> leafchildrens;
    for(auto x : children[u]){
        leafchildrens.push_back(x.nodenumber);
    }

    int i = 0;
    int j = leafchildrens.size() - 1;

    while(j-i > 0){
        int correctlca = query(leafchildrens[i], leafchildrens[j]);
        int mylca = lca(tree, leafchildrens[i], leafchildrens[j], parent);

        if(correctlca != mylca){
            printans(correctlca);
            return;
        }
        i++;
        j--;
    }

    if(i == j){
        int correctlca = query(leafchildrens[i], u);
        printans(correctlca);
        return;
    }

    printans(u);

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

