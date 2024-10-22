/**
 *    author: Saurav
 *    created: 2024.10.23 02:35:48
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

long long f(const vector<int> &arr) {
    // Calculate the total sum of the array
    int n = arr.size();

    vector<int> dp;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
    }

    int target  = sum / 2;
    dp.assign(sum + 1, 0);

    dp[0] = 1;

    for(int i = 0; i<n; i++){
        for(int j = sum ; j>=arr[i]; j--){
            dp[j] |= dp[j - arr[i]];
        }
    }

    int one;
    int two;

    for(int i = target ; i>=0; i--){
        if(dp[i]){
            one = i;
            two = sum - i;
            break;
        }
    }

    return one * two;



}

int subtreesize(vector<vector<int>> &tree, int node, int parent, vector<int> &subtree){
    int cnt = 1;
    for(auto x : tree[node]){
        if(x != parent){
            cnt += subtreesize(tree, x, node, subtree);
        }
    }
    return subtree[node] = cnt;
}

void children(vector<vector<int> > & tree, int node, int par, vector<vector<int> > &childrens){
    childrens[par].push_back(node);

    for(auto x : tree[node]){
        if(x != par){
            children(tree, x, node, childrens);
        }
    }

}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n+1, vector<int> ());

    for(int i= 2; i<=n; i++){
        int x;
        cin>>x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }

    vector<int> subtree(n+1, 0);
    int xx = subtreesize(tree, 1, 0, subtree);
    print(subtree);

    vector<vector<int> > childrens(n+1, vector<int> ());

    children(tree, 1, 0, childrens);

    vector<vector<int> > childrensizes(n+1, vector<int> ());

    for(int i = 1; i<=n; i++){
        for(auto x : childrens[i]){
            childrensizes[i].push_back(subtree[x]);
        }
    }

    print2d(childrensizes);

    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans += f(childrensizes[i]);
    }

    cout<<ans<<endl;

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

