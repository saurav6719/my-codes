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
    while(m>0){
      //cout<<m<<endl;
        int sz;
        cin>>sz;
        if(sz == 0) {
          m--;
          continue;
        }

        if(sz == 1){
          int y;
          cin>>y;
          m--;
          continue;
        }

        vector<int> curr;

        for (int i = 0; i < sz; i++) { // Corrected loop condition
          int x;
          cin >> x;
          curr.push_back(x);
        }

        // for(auto ele : curr){
        //   cout<<ele<<" ";
        // }
        // cout<<endl;
        

        for(int i = 1; i<sz; i++){
          Union(parent,size,curr[i], curr[i-1]);
        }
        m--;
    }

    for(int i = 1; i<=n; i++){
      int xx = find(parent,i);
      cout<<size[xx]<<" ";
    }
    return 0;
}