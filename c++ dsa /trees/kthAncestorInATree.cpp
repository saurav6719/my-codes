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

int getKthAncestor(int node, int k, vector<vector<int> > &binaryParent) {
    int limit = log2(k);
    int xx = node;
    for(int i = 0 ; i<=limit; i++){
        if((1<<i) & k){
            xx = binaryParent[xx][i];
            if(xx == -1) break;
        }
    }
    return xx;
}


void solve(){
    //concept 
    //store first ancestor as parent in a dfs
    //store all the binary power parents in O(nlogn)
    //for any k go to all binary power of node where bit in kk is set O(log n)
    int n;
    cin>>n;
    vector<int> parent(n+5, -1);
    for(int i = 0; i<n-1; i++){
        int a, b;
        parent[b] = a;
    }
    vector<vector<int> > binaryParent;

    int limit = log2(n);

    binaryParent.resize(n+5, vector<int> (limit+5, -1) );
    for(int i = 0; i<n; i++){
        binaryParent[i][0] = parent[i];
    }

    for(int j = 1; j<=limit; j++){
        for(int i = 0; i<n; i++){
            int x = binaryParent[i][j-1];
            if(x == -1) continue;
            int y = binaryParent[x][j-1];
            binaryParent[i][j] = y;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int node;
        cin>>node;
        int k;
        cin>>k;
        cout<<getKthAncestor(node, k, binaryParent);
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

