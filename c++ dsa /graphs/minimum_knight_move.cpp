#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Use boost's hash_combine to combine the hashes
        return h1 ^ h2;  
    }
};
int minimumKnightMoves(int x, int y) {
    vector<vector<int> > dir = {{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
    queue<pair<pair<int, int>, int> > qu;
    unordered_set<pair<int, int> > visited;
    qu.push({{0, 0}, 0});
    visited.insert({0, 0});
    
    while (!qu.empty()) {
        auto cell = qu.front();
        qu.pop();
        int i = cell.first.first;
        int j = cell.first.second;
        int level = cell.second;

        if (i == x && j == y) {
            return level;
        }

        for (int d = 0; d < 8; d++) {
            int nr = i + dir[d][0];
            int nc = j + dir[d][1];
            if (visited.count({nr, nc})) continue;
            qu.push({{nr, nc}, level + 1});
            visited.insert({nr, nc});
        }
    }
    
    return -1;
}

void solve(){
    int x,y;
    cin>>x>>y;
    cout<<minimumKnightMoves(x,y)<<endl;
}
int32_t main(){
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