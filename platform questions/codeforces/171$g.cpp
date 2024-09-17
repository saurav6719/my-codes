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

void dfs1(vector<vector<int> > &tree, int node, vector<int> &aj, vector<int> &bj, map<pp,int> &a, map<pp,int> &b, int curra, int currb  , int par){

    aj[node] = curra;
    bj[node] = currb;

    // debug(node);
    // debug(curra);
    for(auto child :tree[node]){
        if(child != par){
            int newcurra = curra + a[{node, child}];
            int newcurrb = currb + b[{node, child}];
            dfs1(tree, child, aj, bj, a, b, newcurra, newcurrb, node);
        }
    }
    
}

void dfs2(vector<vector<int> > &tree, vector<vector<int> > &binaryparents, int node, int par){
    binaryparents[node][0] = par;

    for(auto child : tree[node]){
        if(child != par){
            dfs2(tree, binaryparents, child, node);
        }
    }
}

void depth(vector<vector<int> > &tree, int node, vector<int> &level, int currlevel, int par){
    level[node] = currlevel;

    for(auto child : tree[node]){
        if(child != par){   
            depth(tree, child, level, currlevel+1, node);
        }
    }

}   


int kthparent(vector<vector<int> > &binaryparent, int node, int k){
    if(k==0) return node;
    int curr = node;
    for(int i = 30; i>=0; i--){
        if((1<<i) & k){
            curr = binaryparent[curr][i];
        }
    }

    return curr;
}


void solve(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n+5, vector<int> ());
    int curr = 2;

    map<pp,int> a;
    map<pp,int> b;


    vector<int> aj(n+5, 0);
    vector<int> bj(n+5, 0);
    for(int i = 0; i<n-1; i++){
        int par;
        cin>>par;
        tree[curr].push_back(par);
        tree[par].push_back(curr);

        int aj;
        int bj;
        cin>>aj>>bj;

        pp aa = {par,curr};
        pp bb = {curr, par};
        a[aa] = aj;
        a[bb] = aj;

        b[aa] = bj;
        b[bb] = bj;

        curr++;

    }

    pp aa = {6,8};
    // debug(a[aa]);
    // debug(b[aa]);

    


    dfs1(tree, 1,aj,bj, a, b, 0,0,0);

    print(aj);
    print(bj);


    vector<vector<int> > binaryparents(n+5, vector<int> (31));

    dfs2(tree, binaryparents, 1, 0);

    for(int i = 0; i<31; i++){
        binaryparents[0][i] = 0;
    }


    // for(int i = 1; i<=n; i++){
    //     cout<<binaryparents[i][0]<<" ";
    // }

    for(int j =1; j<31; j++){
        for(int i = 1; i<=n; i++){
            int half = binaryparents[i][j-1];
            binaryparents[i][j] = binaryparents[half][j-1];
        }
    }

    vector<int> level(n+5);

    depth(tree, 1, level, 0, 0);

    print(level);


    vector<int> ans(n+5, 0);
    for(int i = 2; i<=n; i++){
        int asum = aj[i];
        int bsum = bj[i];

        if(bsum <= asum){
            ans[i] = level[i];
            continue;
        }

        int lo = 0;
        int hi = level[i]+1;

        int res = -1;
        while(lo <= hi){
            int mid =( lo + hi )/ 2;

            int currpar = kthparent(binaryparents, i, mid);
            if(bj[currpar] <= asum){
                res = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        ans[i] = level[i] - res;
    }

    for(int i = 2; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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

