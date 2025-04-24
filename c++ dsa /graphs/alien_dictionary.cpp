
#include<iostream>
#include<list>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > graph;
vector<int> ans;
int v; // number of vertices
unordered_set<int> visited;
void add_edge(int src, int dest, bool undirected = true) {
    graph[src].push_back(dest);
    if (undirected) {
        graph[dest].push_back(src);
    }
}
void topobfs(){
    vector<int> indegree(v,0);
    queue<int> qu;
    for(int i = 0; i<v;i++){
        for(auto neigh : graph[i]){
            indegree[neigh]++;
        }
    }
    for(int i =0; i<v; i++){
        if(indegree[i] == 0) {
            qu.push(i);
            visited.insert(i);
        }
    }
    while(not qu.empty()){
        auto cell = qu.front();
        ans.push_back(cell);
        qu.pop();
        for(auto neighbour: graph[cell]){
            if(not visited.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }   
    }
}
int main() {
    int n;
    cin>>n; // no of words given 
    int k;
    cin>>k;   // no of letters in the language
    v = k;
    graph.resize(v,vector<int> ());
    visited.clear();
    vector<string> dictionary(n);
    for(int i = 0; i<n; i++){
        cin>>dictionary[i];
    }
    unordered_map<char,int> mp;
    unordered_map<int,char> mp2;
    unordered_set<char> st;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<dictionary[i].size(); j++){
            if(st.count(dictionary[i][j] == 0)){
                st.insert(dictionary[i][j]);
                mp[dictionary[i][j]] = cnt;
                mp2[cnt] = dictionary[i][j];
                cnt++;
            }
        }
    }

    for(int i = 0; i<n-1; i++){
        string s1 = dictionary[i];
        string s2 = dictionary[i+1];
        int len = min(s1.size(), s2.size());

        for(int i = 0 ; i<len; i++){
            if(s1[i] != s2[i]){
                add_edge(mp[s1[i]] , mp[s2[i]], false);
                break;
            }
        }
    }

    topobfs();
    string answer ="";
    for(int i = 0; i<ans.size(); i++){
        int ele = ans[i];
        answer += mp2[ele];
    }

    cout<<answer;


}