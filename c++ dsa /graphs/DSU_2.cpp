#include<iostream>
#include<vector>
using namespace std;
vector<int> maxi;
vector<int> mini;
int find(vector<int> &parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent,parent[x]);
}
void Union(vector<int> &parent,vector<int> &size, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a==b) return;
    if(size[a] >= size[b]){
        size[a]+= size[b];
        parent[b] = a;
        mini[a] = min(mini[a], mini[b]);
        maxi[a] = max(maxi[a], maxi[b]);
    }
    else{
        size[b]+= size[a];
        parent[a] = b;
        mini[b] = min(mini[a], mini[b]);
        maxi[b] = max(maxi[a], maxi[b]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; //no of elements
    int m; // no of queries
    cin>>n>>m;
    maxi.resize(n+1);
    mini.resize(n+1);

    vector<int> parent(n+1);
    vector<int> size(n+1,1);
    for(int i = 0; i<=n ; i++){
        parent[i] = i;
        maxi[i] = i;
        mini[i] = i;
    }
    while(m--){
        string str; // union or find
        cin>>str;

        if(str == "union"){
            int x,y;
            cin>>x>>y;
            Union(parent,size,x,y);
        }
        else{
            int x;
            cin>>x;
            int p = find(parent,x);
            cout<<mini[p]<<" "<<maxi[p]<<" "<<size[p]<<endl;
        }
    }
    return 0;
}