#include<iostream>
#include<vector>
using namespace std;

vector<int> parents;
vector<int> points;
vector<int> extra_points;
vector<int> sizes;


int find(int x){
    return parents[x] == x ? x : find(parents[x]);

}

int get_points(int n) {
    int amt = points[n];
    if (parents[n] == n) {
        return amt;
    }
    amt += get_points(parents[n]) - extra_points[n];
    return amt;
}

void add_points(int n, int p) {
    int top = find(n);
    points[top] += p;
}

bool link(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) {
        return false;
    }
    if (sizes[n1] < sizes[n2]) {
        std::swap(n1, n2);
    }
    sizes[n1] += sizes[n2];
    parents[n2] = n1;
    extra_points[n2] = points[n1];
    return true;
}






// void Union(vector<int> &parent,vector<int> &size, int a, int b, vector<int> &point, vector<int> &extra){
//     a = find(parent,a);
//     b = find(parent,b);
//     if(a==b) return;
//     if(size[a] < size[b]){
//         swap(a,b);
//     }
//     size[a] += size[b];
//     parent[b] = a;
//     extra[b] = point[a];

// }

// void add(int x, int v, vector<int> &parent, vector<int> &point){
//     int par = find(parent, x);
//     point[par] += v;
// }

// int get(int x, vector<int> &extra, vector<int> &point, vector<int> & parent){
//     int amount = point[x];
//     if(parent[x] == x){
//         return amount;
//     }
//     amount += (get(parent[x], extra, point, parent) - extra[x]);
//     return amount;
// }


int main(){
    int n; //no of elements
    int m; // no of queries
    cin>>n>>m;
    parents.resize(n+5);
    points.resize(n+5, 0);
    extra_points.resize(n+5,0);
    sizes.resize(n+5, 1);
    for(int i = 0; i<=n ; i++){
        parents[i] = i;
    }
    while(m--){
        string str; // union or find
        cin>>str;

        if(str == "add"){
            int x,y;
            cin>>x>>y;
            add_points(x,y);
        }
        else if(str == "join"){
            int x, y;
            cin>>x>>y;
            link(x, y);
        }
        else{
            int x;
            cin>>x;
            cout<<get_points(x)<<endl;
        }
    }
    return 0;
}