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
// Example using BFS
bool canReachEnd(vector<int> &input, int k) {
    int n = input.size();
    vector<bool> visited(n, false);
    queue<pair<int, long long>> q; // Pair of position and current sum
    q.push({k, input[k]});
    visited[k] = true;

    while(!q.empty()) {
        auto [pos, sum] = q.front(); q.pop();

        if(pos == 0 || pos == n-1) return true;

        // Move Left
        if(pos > 0 && !visited[pos-1] && sum + input[pos-1] >= 0){
            q.push({pos-1, sum + input[pos-1]});
            visited[pos-1] = true;
        }

        // Move Right
        if(pos < n-1 && !visited[pos+1] && sum + input[pos+1] >= 0){
            q.push({pos+1, sum + input[pos+1]});
            visited[pos+1] = true;
        }
    }

    return false;
}

void solve(){
    int n, k;
    cin >> n >> k;
    // Adjust k based on indexing
    k--;

    vector<int> input(n);
    for(auto &ele : input) cin >> ele;

    if(canReachEnd(input, k)) cout << "YES\n";
    else cout << "NO\n";
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

