/**
 *    author: Saurav
 *    created: 2024.12.10 03:07:04
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

void subtreedfs(int node, int par, vector<vector<int> > &tree, vector<int> &subtreesizes){
    subtreesizes[node] = 1;
    for(auto child : tree[node]){
        if(child != par){
            subtreedfs(child, node, tree, subtreesizes);
            subtreesizes[node] += subtreesizes[child];
        }
    }
}

void dfs2(vector<vector<int> > &tree, int node, int par, vector<int> &subtreesizes, vector<int> &maxchildsize){
    int maxchild = 0;
    for(auto child : tree[node]){
        if(child != par){
            maxchild = max(maxchild, subtreesizes[child]);
        }
    }
    maxchildsize[node] = maxchild;
    for(auto child : tree[node]){
        if(child != par){
            dfs2(tree, child, node, subtreesizes, maxchildsize);
        }
    }
}

void dfs3(vector<vector<int> > &tree, int node, int par, vector<int> &subtreesizes, vector<int> &sumchildsize){
    int sumchild = 0;
    for(auto child : tree[node]){
        if(child != par){
            sumchild += subtreesizes[child];
        }
    }
    sumchildsize[node] = sumchild;
    for(auto child : tree[node]){
        if(child != par){
            dfs3(tree, child, node, subtreesizes, sumchildsize);
        }
    }
}

void dfs(vector<vector<int> > &tree, int node, int par, vector<int> &subtreesizes, vector<int> &ans, vector<vector<int> > &directchildrens, vector<int> &maxchildsize, vector<int> &sumchildsize, vector<int> &parent){
    for(auto child : tree[node]){
        if(child != par){
            dfs(tree, child, node, subtreesizes, ans, directchildrens, maxchildsize, sumchildsize, parent);
        }
    }

    set<int> possiblecandidates;

    possiblecandidates.insert(node);

    int maximumsizeofchild = 0;
    int maximumchild = -1;

    for(auto child : tree[node]){
        if(child != par){
            if(subtreesizes[child] > maximumsizeofchild){
                maximumsizeofchild = subtreesizes[child];
                maximumchild = child;
            }
        }
    }

    if(maximumchild != -1){
        int centroidofchild = ans[maximumchild];
        while(centroidofchild != node){
            int ele = centroidofchild;
            vector<int> afterthis;
            int cnt = 0;
            cnt += sumchildsize[ele];
            afterthis.push_back(maxchildsize[ele]);
            afterthis.push_back(subtreesizes[node] - cnt - 1);
            sort(afterthis.begin(), afterthis.end());
            if(afterthis.back() <= subtreesizes[node] / 2){
                ans[node] = ele;
                return;
            }
            centroidofchild = parent[centroidofchild];
        }
    }

    for(auto ele : possiblecandidates){
        vector<int> afterthis;
        int cnt = 0;
        cnt += sumchildsize[ele];
        afterthis.push_back(maxchildsize[ele]);
        afterthis.push_back(subtreesizes[node] - cnt - 1);
        sort(afterthis.begin(), afterthis.end());
        if(afterthis.back() <= subtreesizes[node] / 2){
            ans[node] = ele;
            return;
        }
    }

    return ;
}
void solve(){

    int n;
    int q; 
    cin>>n;
    cin>>q;
    vector<vector<int> > tree(n+1, vector<int> ());
    vector<vector<int> > directchildrens(n+1, vector<int> ());
    vector<int> parent(n+1, 0);
    vector<int> subtreesizes(n+1);
    for(int i = 2; i<=n; i++){
        int par;
        cin>>par;
        parent[i] = par;
        tree[par].push_back(i);
        tree[i].push_back(par);
        directchildrens[par].push_back(i);
    }

    vector<int> ans(n+1,0);

    subtreedfs(1, 0, tree, subtreesizes);

    vector<int> maxchildsize(n+1, 0);

    dfs2(tree, 1, 0, subtreesizes, maxchildsize);

    vector<int> sumchildsize(n+1, 0);

    dfs3(tree, 1, 0, subtreesizes, sumchildsize);

    dfs(tree, 1, 0, subtreesizes, ans, directchildrens, maxchildsize, sumchildsize, parent);

    while(q--){
        int node;
        cin>>node;
        cout<<ans[node]<<endl;
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

