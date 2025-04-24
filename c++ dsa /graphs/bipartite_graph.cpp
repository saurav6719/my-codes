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
//link -> https://leetcode.com/problems/is-graph-bipartite/
void solve(){
    class Solution {
public:

bool bfs(int src, vector<vector<int>>& graph,vector<int> &color){
    queue<int> qu;
        int n = graph.size();
        qu.push(src);
        color[src] = 0;
        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();
            
            for(auto neighbour : graph[curr]){
                if(color[neighbour] == -1){
                    color[neighbour] = !color[curr];
                    qu.push(neighbour);
                }
                else if(color[curr] == color[neighbour]) return false;
            }
        }
        return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                if(bfs(i,graph,color) == false) return false;
            }
        }
        return true;

    }
};
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