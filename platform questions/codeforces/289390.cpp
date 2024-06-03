#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> &parent, int x, vector<int> &score){
    if(parent[x] == x) {
        return x;
    }
    int par = find(parent,parent[x], score);
    score[x] += score[par];
    return parent[x];
}

void Union(vector<int> &parent,vector<int> &rank,vector<int> &score,  int a, int b){
    a = find(parent,a, score);
    b = find(parent,b, score);
    if(rank[a] >= rank[b]){
        rank[a]++; 
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}

void add(vector<int> &parent, int x, int v, vector<int> & score){
    int par = parent[x];
    score[par] += v;
}
int main(){
    int n; //no of elements
    int m; // no of queries
    cin>>n>>m;
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i = 0; i<=n ; i++){
        parent[i] = i;
    }

    vector<int> score(n+1, 0);
    while(m--){
        string str; // union or find
        cin>>str;

        if(str == "join"){
            int x,y;
            cin>>x>>y;
            Union(parent,rank,score, x,y);
        }
        else if(str == "add"){
            int x, y;
            cin>>x>>y;
            add(parent, x, y, score);
        }
        else{
            int x;
            cin>>x;
            find(parent,x, score);
            cout<<score[x]<<endl;

        }
    }
    return 0;
}