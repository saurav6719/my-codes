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
#define pp pair<int,int> 
using namespace std;

/* write core logic here */

bool cmp(pp &a, pp&b){
    return a.first > b.first;
}
vector<int> height;

int depth(vector<vector<int> > &tree, int src, int par){
    if(tree[src].size() == 1 and src!= 1){
        return height[src] = 0;
    }  
    int ans = 0;
    for(int child : tree[src]){
        if(child == par) continue;
        ans = max(ans, 1+ depth(tree, child , src));
    } 

    return height[src] = ans;
}
vector<int> final;

int f(vector<vector<int> > &tree, int src , int par , int partial_ans){
    vector<int> prf;
    vector<int> suf;
    for(auto child : tree[src]){
        if(child == par) continue;
        prf.push_back(height[child]);
        suf.push_back(height[child]);
    }
    for(int i = 1; i<prf.size(); i++){
        prf[i] = max(prf[i-1] , prf[i]);
    }
    for(int i = suf.size() - 2 ; i>=0; i--){
        suf[i] = max(suf[i+1] , suf[i]);
    }
    int ans1 = INT_MIN;
    int child_no = 0;
    for(int child : tree[src]){
        if(child == par) continue;
        int op1;
        if(child_no == 0) op1 = INT_MIN;
        else op1 = prf[child_no-1];
        int op2;
        if(child_no == suf.size()-1) op2 = INT_MIN;
        else op2 = suf[child_no + 1];
        ans1 = 1+max(max(op1, op2) ,partial_ans);
        int xx = f(tree, child, src, ans1);
        child_no++;
    }

    return final[src] =  1+ max( partial_ans , (prf.empty() ? -1 : prf.back()));
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
    final.resize(n+5);
    int xx = depth(tree, 1, 0);
    int yy = f(tree, 1, 0, -1);
    for(int i = 1; i<=n; i++){
        cout<<final[i]<<" ";
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

