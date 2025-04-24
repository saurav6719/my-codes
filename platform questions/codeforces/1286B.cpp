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

vector<pp>  f(vector<vector<int> > &tree, int node, vector<int> &value, vector<int> &res, int &curr, int &curr2){
    vector<pp> ans;
    if(tree[node].size() == 0 and value[node] == 0){
        ans.push_back({curr , node});
        res[node] = curr;
        curr++;
        return ans;
    }
    if(tree[node].size() == 0 and value[node] != 0){
        return {};
    }

    for(auto child : tree[node]){
        vector<pp> temp = f(tree, child, value, res, curr, curr2);
        if(temp.size() == 0) return {};
        for(auto x : temp){
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size() < value[node]) return {};

    vector<pp> newans;
    for(int i = 0; i<value[node]; i++){
        newans.push_back(ans[i]);
    }

    if(newans.size() == 0) {
        newans.push_back({1 , node});
    }
    else newans.push_back({newans.back().first +1 , node});

    res[node] = newans.back().first;

    int incr = 5;

    
    for(int i = value[node]; i<ans.size(); i++){
        
        newans.push_back({ans[i].first + incr , ans[i].second});
    }

    debug(node);

    return newans;
}
void solve(){
    int n;
    cin>>n;

    vector<vector<int> > tree(n+5, vector<int> ());

    int root = -1;

    vector<int> value(n+5);

    for(int i= 1; i<=n; i++){
        int par;
        cin>>par;
        if(par == 0) root = i;
        int val;
        cin>>val;
        value[i] = val;
        if(par != 0){
            tree[par].push_back(i);
        }
    }
    vector<int> res2(n+5);
    int curr = 1;
    int curr2 = 1;
    vector<pp> ans = f(tree, root, value, res2, curr, curr2);

    if(ans.size() == 0){
        cout<<"NO"<<endl;
        return;
    }

    else{
        cout<<"YES"<<endl;
    }

    vector<int> res(n+5);
    
    for(int i = 0; i<ans.size(); i++){
        res[ans[i].second] = ans[i].first;
    }

    for(int i = 1; i<=n; i++){
        cout<<res[i]<<" ";
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}