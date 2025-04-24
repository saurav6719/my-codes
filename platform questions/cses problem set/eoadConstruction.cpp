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
vector<int> ans;
vector<int> maxsize;
int find(vector<int> &parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent,parent[x]);
}
void Union(vector<int> &parent,vector<int> &size, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a==b) {
        ans.push_back(ans[ans.size() - 1]);
        maxsize.push_back(maxsize[maxsize.size() -1]);
        return;
    }
    if(size[a] >= size[b]){
        size[a]+= size[b];
        parent[b] = a;
        ans.push_back(ans[ans.size() - 1] - 1);
        maxsize.push_back(max(maxsize[maxsize.size()-1] , size[a]));
    }
    else{
        size[b]+= size[a];
        parent[a] = b;
        ans.push_back(ans[ans.size() - 1] - 1);
        maxsize.push_back(max(maxsize[maxsize.size()-1] , size[b]));
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    ans.push_back(n);
    maxsize.push_back(1);
    vector<int> parent(n+5);
    for(int i = 1; i<=n; i++){
        parent[i] = i;
    }
    vector<int> size(n+5,1);
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        Union(parent,size,a,b);
        // debug(ans[ans.size() - 1]);
        // debug(maxsize[maxsize.size() - 1]);
    }

    for(int i = 1; i<=m; i++){
        cout<<ans[i]<<" "<<maxsize[i]<<endl;
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

