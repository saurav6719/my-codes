#include<iostream>
#include<vector>
#include<set>
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
    }
    else{
        size[b]+= size[a];
        parent[a] = b;
    }
}

const int MOD = 1e9 + 7;

// Function to calculate power in modular arithmetic

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1; // y = y/2
        x = (x * x) % MOD;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; //no of elements
    int m; // no of queries
    cin>>n>>m;
    //cout<<n<<" "<<m<<endl;

    int ans = power(n,m);
    int m_copy = m;
   // cout<<ans<<endl;

    vector<int> parent(n+1);
    vector<int> size(n+1,1);
    for(int i = 0; i<=n ; i++){
        parent[i] = i;
    }
    int q = n-1;
    while(q--){
        int u,v,color;
        cin>>u>>v>>color;
        if(color == 0){
            Union(parent, size , u, v);
        }
    }

    
    set <int> visited;

    for(int i = 1; i<=n; i++){
        int xx = find(parent , i);
        //cout<<"xx"<<" "<<xx<<endl;
        if(visited.count(xx)) continue;
        int aa = size[xx];
        //cout<<"aa"<<" "<<aa<<endl;
        visited.insert(xx);
        int curr = power(aa,m_copy);
        //cout<<"curr"<<" "<<curr<<endl;
        ans = (ans - curr + MOD) % MOD;

    }

    cout<<ans<<endl;
    return 0;
}