/**
 *    author: Saurav
 *    created: 2025.05.01 05:23:43
 *    We stop at Candidate Master in 2025
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define printset(s)
#define printpp(v)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */

void dfs(int node, int par, vector<int> &parent, vector<vector<int> > &tree) {
    parent[node] = par;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node, parent, tree);
        }
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> colors(n+1, 2);
    for(int i = 1; i<=n; i++){
        cin>>colors[i];
    }

    vector<vector<int> > tree(n+1);
    for(int i  =0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> parent(n+1, -1);

    dfs(1, 0, parent, tree);

    map<int,set<int> > isparentkeyehchildrenblackhai;
    set<int> yehblackbutparentnotblack;
    set<pp> parentcountofblackchildren;

    for(int i = 1; i<=n; i++){
        if(colors[i] == 1){
            // this node is black
            int par = parent[i];
            isparentkeyehchildrenblackhai[par].insert(i);
            if(colors[par] != 1){
                yehblackbutparentnotblack.insert(i);
            }
        }
    }

    for(auto ele : isparentkeyehchildrenblackhai){
        int par = ele.first;
        int count = ele.second.size();
        if(count > 0){
            parentcountofblackchildren.insert({count, par});
        }
    }

    printset(yehblackbutparentnotblack);

    // for(auto ele : parentcountofblackchildren){
    //     debug(ele.first);
    //     debug(ele.second);
    // }

    int cnt = yehblackbutparentnotblack.size();
    debug(cnt);

    while(q--){
        int node;
        cin>>node;

        //toggle this node 
        if(colors[node] == 1){
            // this node was black 
            int par = parent[node];
            int prevcount = isparentkeyehchildrenblackhai[par].size();
            if(parentcountofblackchildren.count({prevcount, par}))parentcountofblackchildren.erase({prevcount, par});
            int newcount = prevcount - 1;
            if(newcount > 0){
                parentcountofblackchildren.insert({newcount, par});
            }
            isparentkeyehchildrenblackhai[par].erase(node);
            if(isparentkeyehchildrenblackhai[par].size() == 0){
                isparentkeyehchildrenblackhai.erase(par);
            }
            // if(yehblackbutparentnotblack.count(node))yehblackbutparentnotblack.erase(node);

            // for(auto ele : isparentkeyehchildrenblackhai[node]){
            //     yehblackbutparentnotblack.insert(ele);
            // }
            if(colors[par] != 1){
                cnt --;
            }

            cnt += isparentkeyehchildrenblackhai[node].size();

            colors[node] = 0; // now this node is white
        }
        else{
            // this node was white
            int par = parent[node];
            int prevcount = isparentkeyehchildrenblackhai[par].size();
            isparentkeyehchildrenblackhai[par].insert(node);
            if(parentcountofblackchildren.count({prevcount, par}))parentcountofblackchildren.erase({prevcount, par});
            int newcount = prevcount + 1;
            parentcountofblackchildren.insert({newcount, par});
            if(colors[par] != 1){
                cnt++;
            }
            

            // for(auto ele : isparentkeyehchildrenblackhai[node]){
            //     yehblackbutparentnotblack.erase(ele);
            // 
            cnt -= isparentkeyehchildrenblackhai[node].size();
            colors[node] = 1; // now this node is black
        }

        debug(cnt);


        if(cnt > 1){
            cout<<"No"<<endl;
            continue;
        }

        if(cnt == 0){
            cout<<"No"<<endl;
            continue;
        }
        

        
        if(parentcountofblackchildren.size() == 1){
            cout<<"Yes"<<endl;
            continue;
        }

        if(parentcountofblackchildren.size() > 1){
            auto [count, par] = *parentcountofblackchildren.rbegin();
            debug(count);
            debug(par);
            if(count == 1){
                cout<<"Yes"<<endl;
                continue;
            }
            if(count > 2){
                cout<<"No"<<endl;
                continue;
            }
            if(count == 2){
                if(colors[parent[par]]!=1){
                    // this is root 
                    // checking second best 
                    auto it = parentcountofblackchildren.rbegin();
                    it++;
                    auto [secondcount, secondpar] = *it;
                    if(secondcount == 2){
                        cout<<"No"<<endl;
                        continue;
                    }
                    cout<<"Yes"<<endl;
                    continue;
                }
                else{
                    cout<<"No"<<endl;
                    continue;
                }
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

