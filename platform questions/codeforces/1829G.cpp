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
vector<vector<pp> > grid(2024,vector<pp> (2024, {0,0}));
vector<vector<int>> prefixSum(2024, vector<int>(2024, 0));

map<int,int> mp;

void f(){
    int curr =1;
    for(int i = 0; i<=2023; i++){
        int a = i;
        int b = 0;
        for(int j = 0; j<=i; j++){
            grid[a][b] = {curr, curr * curr};
            curr++;
            a--;
            b++;
        }
    }


    // Compute the prefix sum
    for (int i = 0; i < 2024; ++i) {
        for (int j = 0; j < 2024; ++j) {
            // Calculate prefix sum for each cell
            prefixSum[i][j] = grid[i][j].second;
            if (i > 0) prefixSum[i][j] += prefixSum[i-1][j];
            if (j > 0) prefixSum[i][j] += prefixSum[i][j-1];
            if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
        }
    }

    for (int i = 0; i < 2024; ++i) {
        for (int j = 0; j < 2024; ++j) {
            int ff = grid[i][j].first;
            int ss = prefixSum[i][j];

            mp[ff] = ss;
        }
    }

    // print2d(prefixSum);
}
void solve(){
    int n;
    cin>>n;

    cout<<mp[n]<<endl;

    

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

    f();
    while(t--){
        solve();
    }
return 0;
}

