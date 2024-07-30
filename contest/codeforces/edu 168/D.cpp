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
void decreaseSubtreeValues(int node, int parent, vector<vector<int>>& adj, vector<int>& values, int x) {
    // Decrease the value of the current node
    values[node] -= x;

    // Traverse all adjacent nodes
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            decreaseSubtreeValues(neighbor, node, adj, values, x);  // Recursive DFS call
        }
    }
}
void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values, vector<int>& subtreeSum) {
    // Initialize the subtree sum for the current node
    subtreeSum[node] = values[node];

    // Traverse all adjacent nodes
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, adj, values, subtreeSum);  // Recursive DFS call
            subtreeSum[node] += subtreeSum[neighbor];  // Add the subtree sum of the child to the current node
        }
    }
}

bool poss(int mid , vector<int> &values, vector<vector<int> > &tree, int n){

    int req = (mid - values[1]);
    debug(req);
    debug(values[1]);
    vector<int> newvalues = values;
    print(newvalues);   
    decreaseSubtreeValues(1, 0, tree, newvalues, req);
    newvalues[1] = req;

    print(newvalues);

    vector<int> subtreeSum(n+5, 0);
    dfs(1,0,tree,newvalues, subtreeSum);

    for(int i = 1; i<=n; i++){
        if(subtreeSum[i] < 0) return false;
    }

    print(subtreeSum);
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> values(n+1);
    for(int i= 1; i<=n; i++){
        cin>> values[i];
    }
    vector<vector<int> > tree(n+5, vector<int> ());

    for(int i = 2; i<=n; i++){
        int parent ;
        cin>>parent;
        tree[parent].push_back(i);
        tree[i].push_back(parent);
    }
    vector<int> stsum(n+5);
    int lo = values[1];
    int hi = 15;
    int res = values[1];
    debug(values[1]);
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        debug(mid);
        if(poss(mid, values, tree, n)){
            res = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

