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
bool xxy = false;
int f(vector<vector<int>>& tree, vector<int>& subtreeSize, vector<int>& components, int i, int x, int par) {
    int sz = 0; // Size of the current subtree

    for (auto child : tree[i]) {
        if (child == par) continue;

        int childSize = f(tree, subtreeSize, components, child, x, i);

        if (childSize >= x) {
            debug(x);
            components[i] ++;
        } else {
            sz += childSize;
        }
    }
    return subtreeSize[i] = 1 + sz;
}

bool poss(int mid, vector<vector<int>>& tree, vector<int>& subtreeSize, vector<int>& components,  int n, int k){
    subtreeSize.clear();
    subtreeSize.resize(n+5, 0);
    components.clear();
    components.resize(n+5, 0);

    int xx = f(tree, subtreeSize, components, 1, mid, 0);
    int cnt = 0;

    for(auto ele : components){
        cnt += ele;
    }

    if(subtreeSize[1] < mid) cnt--;
    debug(mid);
    print(subtreeSize);
    print(components);

    if(cnt >= k) return true;

    return false;

}
void solve(){
    int n;
    cin>>n;
    int k; cin>>k;

    vector<vector<int> > tree(n+5, vector<int> ());
    for(int i = 0; i<n-1; i++){
        int u;cin>>u;
        int v;cin>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> subtreeSize(n+5, 0);
    vector<int> components(n+5, 0);

    int lo = 0;
    int hi = 1e6;
    int res = -1;
    while(lo <= hi){
        int mid = (lo + hi) /2;
        if(poss(mid, tree, subtreeSize, components, n, k)){
            res =mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    debug(xxy);

    cout<<res<<endl;
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

