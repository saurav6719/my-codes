#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int 
using namespace std;

int find(vector<int> &parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent,parent[x]);
}

void Union(vector<int> &parent,vector<int> &rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a==b) return;
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}

// making edge list weighted struct 

struct edge {
    int src;
    int dest;
    int weight;
};

//custom comparator accoridng to weights 
bool cmp (edge e1, edge e2){
    return e1.weight < e2.weight;
}

// kruskals algorithm

ll kruskals (vector<edge> &input, int n, int e){ // n = no of vertices e = no of edges
    sort(input.begin(), input.end(), cmp);
    vector<int> parent (n+1);
    vector<int> rank(n+1,1);
    for(int i = 0 ; i<n ; i++){
        parent[i] = i;
    }
    int edgeCount = 0;
    int i = 0;
    ll ans = 0;
    while(edgeCount <= n-1 and i < input.size()){ // in a tree edge count == n-1 exactly 
        edge curr = input[i];
        int srcPar = find(parent , curr.src);
        int destPar = find(parent, curr.dest);
        if(srcPar != destPar){ // will not form cycle 
            Union(parent, rank , srcPar, destPar);
            ans += curr.weight;
            edgeCount ++;
        }   
        i++;
    }
    return ans;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<edge> v(e);
    for(int i = 0; i<e; i++){
        cin>>v[i].src>>v[i].dest>>v[i].weight;
    }
    cout<<kruskals(v,n,e);
    return 0;
}