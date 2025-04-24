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
vector<int> diameter;
vector<int> height;
int depth(vector<vector<int> >&tree, int src, int par){
    if(tree[src].size() == 1 and src!= 1){
        return height[src] = 0;
    }

    int ans = 0;
    for(int child : tree[src]){
        if(child == par) continue;
       ans = max(ans, depth(tree, child, src));
    }
    return height[src] = 1+ans;
}


int f(vector<vector<int> > &tree, int src, int par){
    if(tree[src].size() == 1 and src!=1){
        return diameter[src] = 0;
    }
    int ans = 0;
    for(int child : tree[src]){
        if(child != par){
            ans = max(ans, f(tree, child, src));
        }
    }

    vector<int> v;

    for(int child : tree[src]){
        if(child == par) continue;
        v.push_back(height[child]);
    }

    sort(v.begin(), v.end(), greater<int> ());

    diameter[src] = max(diameter[src] , ans);
    if(v.size() == 0) diameter[src] = 0;
    else if(v.size() == 1) diameter[src] = max(diameter[src] , 1+v[0]);
    else {
        diameter[src] = max(diameter[src] , 2+v[0]+v[1]);
    }

    return diameter[src];

}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n+1, vector<int> ());
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    height.resize(n+5, 0);
    diameter.resize(n+5, 0);
   int xx =  depth(tree, 1, 0);
   cout<<f(tree, 1, 0);

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

