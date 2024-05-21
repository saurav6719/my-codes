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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
int length(int leaf, int stone, vector<vector<int> > &graph, set<int> &visited, int ans){
    if(stone == leaf) return ans;
    visited.insert(stone);
    for(auto neigh : graph[stone]){
        if(!visited.count(neigh)){
            int res = -1;
            res = length(leaf, neigh, graph, visited, ans+1);
            if(res != -1) return res;
        }
    }
    return -1;
}

void solve(){
    int n;
    int t;
    cin>>n>>t;
    vector<vector<int> > graph(n+1, vector<int>());
    for(int i = 0; i<n-1; i++){
        int a;
        int b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int leaf1 = -1;
    int leaf2 = -1;
    for(int i =1 ; i<=n; i++){
        if(graph[i].size() == 1){
            if(leaf1 == -1){
                leaf1 = i;
                continue;
            }
            leaf2 = i;
        }
    }

    int stone ;
    cin>>stone;
    set<int> visited;

    debug(leaf1);
    debug(leaf2);

    if(stone != leaf1 and stone != leaf2){
        int x1 = length(leaf1, stone, graph, visited, 0 );
        debug(x1);
        visited.clear();
        int x2 = length(leaf2, stone, graph, visited, 0 );
        debug(x2);
        visited.clear();
        if(x1 & 1 or x2 & 1){
            cout<<"Ron"<<endl;
            return;
        }
        cout<<"Hermione"<<endl;
        return;
    }

    if(stone == leaf1){
        int x1 = length(leaf2, stone, graph, visited, 0 );
        visited.clear();
        if(x1 & 1){
            cout<<"Ron"<<endl;
            return;
        }
        cout<<"Hermione"<<endl;
        return;
    }


    if(stone == leaf2){
        int x1 = length(leaf1, stone, graph, visited, 0 );
        visited.clear();
        if(x1 & 1){
            cout<<"Ron"<<endl;
            return;
        }
        cout<<"Hermione"<<endl;
        return;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

