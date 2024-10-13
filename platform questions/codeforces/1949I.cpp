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
struct circle{
    int x,y,r;
};

bool istouching(circle a, circle b){
    int dist = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    int rad = (a.r + b.r)*(a.r + b.r);
    return dist == rad;
}

bool checkbipartite(vector<vector<int> > &graph, int node, vector<int> &color, vector<int> &visited,  int&cnta, int &cntb, bool &ans){
    visited[node] = 1;
    for(auto ele : graph[node]){
        if(visited[ele] == 0){
            color[ele] = 1 ^ color[node];
            if(color[ele] == 1) cnta++;
            else cntb++;
            if(!checkbipartite(graph, ele, color, visited, cnta, cntb, ans)){
                ans = false;
            }
        }
        else if(color[ele] == color[node]){
            debug(node);
            debug(ele);
            ans = false;
        }
    }

    if(node == 0) debug(cnta);
    if(node == 0) debug(cntb);

    if(!ans) return false;


    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<circle> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].x>>v[i].y>>v[i].r;
    }
    vector<vector<int> > touch(n, vector<int> ());

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            if(istouching(v[i], v[j])){
                touch[i].push_back(j);
                // touch[j].push_back(i);
            }
        }
    }

    print2d(touch);

    // now i have a graph and i need to check if there is any connected component which is
    // bipartite as well as it has both colours different in number of nodes

    vector<int> color(n, -1);
    vector<int> visited(n, 0);
    for(int i=0;i<n;i++){
        int cnta = 0;
        int cntb = 1;

        if(visited[i] == 0){
            debug(i);

            bool ans = true;

            color[i] = 0;
            if(checkbipartite(touch, i, color, visited,cnta, cntb, ans)){
                if(cnta != cntb){
                    cout<<"YES"<<endl;
                    return;
                }
            }
            print(visited);
            print(color);

        }
    }

    cout<<"NO"<<endl;



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

