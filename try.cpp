/**
 *    author: Saurav
 *    created: 2024.11.15 03:17:24
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
map<int, vector<pp> >mp;
int f(int node, vector<vector<int> > &tree , int par, int k, vector<int> &childrencount, vector<int> &score){
    // answer if this node is in k paths 

    int ans =  (score[node] * k);

    if(k==0) return 0;

    for(auto ele : mp[node]){
        if(ele.first == k) return ele.second;
    }

    // debug(ans);


    int noofchildren = childrencount[node];

    if(noofchildren == 0){
        return ans;
    }

    // debug(noofchildren);

    vector<int> dp1;
    vector<int> dp2;
    vector<int> iftakensingle;

    int x1 = k / noofchildren;
    int x2 = k / noofchildren + 1;

    int remain;
    if(noofchildren == 0){
        remain = 0;
    }else{
        remain = k % noofchildren;
    }

    // debug(x1);
    // debug(x2);
    // debug(remain);

    for(auto child : tree[node]){
        if(child == par) continue;
        // debug(child);
        int ans1 = f(child, tree, node, x1, childrencount, score);
        if(remain > 0){
            int ans2 = f(child, tree, node, x2, childrencount, score);
            dp2.push_back(ans2);
            iftakensingle.push_back(ans2 - ans1);
        }
        dp1.push_back(ans1);
    }

    sort(iftakensingle.begin(), iftakensingle.end(), greater<int>());

    
    for(int i = 0; i<dp1.size(); i++){
        ans += dp1[i];
    }

    debug(node);
    debug(ans);

    for(int i = 0; i < remain; i++){
        ans += iftakensingle[i];
    }

    mp[node].push_back({k, ans});

    return ans;
}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<vector<int> > tree(n+1, vector<int> ());

    mp.clear();

    vector<int> childrencount(n+1, 0);

    for(int i = 2; i<=n; i++){
        int par;
        cin>>par;
        childrencount[par]++;
        tree[par].push_back(i);
        tree[i].push_back(par);
    }
    vector<int> score(n+1);
    for(int i = 1; i<=n; i++){
        cin>>score[i];
    }

    int ans = f(1, tree, 0, k, childrencount, score);

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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

