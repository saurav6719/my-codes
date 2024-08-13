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
void fillGrid(int n, int m, int k, vector<vector<int>> &grid) {
    

    for (int i = 0; i < n; ++i) {
        int multiplier = (i < k) ? i + 1 : min(k, n - i);
        int val = 1;
        int j = 0;

        // Fill increasing values from 1 to k
        for (; j < k && j < m; ++j) {
            grid[i][j] = multiplier * val;
            val++;
        }

        // Fill with k if more than k-1 columns left
        for (; j < m - (k - 1); ++j) {
            grid[i][j] = multiplier * k;
        }

        // Fill decreasing values from k-1 down to 1
        for (val = k - 1; j < m; ++j) {
            grid[i][j] = multiplier * val;
            val--;
        }
    }

    // Print the grid
    for (const auto &row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int> > graph(n , vector<int> (m, 0));

    fillGrid(n,m,k, graph);
    map<int,int> mp;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            mp[graph[i][j]]++;
        }
    }

    int w;
    cin>>w;
    vector<int> input(w);
    for(int i = 0; i<w; i++){
        cin>>input[i];
    }

    sort(input.begin(), input.end(), greater<int> ());

    vector<int> xx;

    for(auto ele : mp){
        for(int i= 0;i<ele.second; i++){
            xx.push_back(ele.first);
        }
    }

    reverse(xx.begin(), xx.end());

    print(xx);

    int ans = 0;
    for(int i = 0; i<w; i++){
        ans += (input[i] * xx[i]);
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
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

