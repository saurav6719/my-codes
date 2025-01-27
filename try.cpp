#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9+5;

// Fenwick (BIT) for point updates, range sum queries
struct Fenwick {
    int n;
    vector<int> fenw;
    Fenwick(int n) : n(n), fenw(n+1, 0) {}

    void update(int i, int delta) {
        // i is 0-based externally, but Fenwicks typically are 1-based internally
        i++; 
        while(i <= n){
            fenw[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) const {
        // sum from 0..i inclusive
        int s = 0; 
        i++;
        while(i > 0){
            s += fenw[i];
            i -= i & -i;
        }
        return s;
    }

    int rangeQuery(int l, int r) const {
        if(l > r) return 0;
        return query(r) - ((l==0)?0:query(l-1));
    }
};

static const int MAXN = 400000; 
vector<int> gAdj[MAXN+1];
int gVal[MAXN+1];
int gIn[MAXN+1], gOut[MAXN+1];
bool gVisited[MAXN+1];

int n; // number of nodes
int timer;
vector<int> eulerOrder; 

void dfsEuler(int u, int p){
    gIn[u] = timer++;
    eulerOrder.push_back(u);
    for (int c: gAdj[u]){
        if(c == p) continue;
        dfsEuler(c, u);
    }
    gOut[u] = timer-1;
}

void solveOneTest(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> gVal[i];
    }

    for(int i=1; i<=n; i++){
        gAdj[i].clear();
        gVisited[i] = false;
    }


    for(int i=0; i< (n-1); i++){
        int u,v; 
        cin >> u >> v;
        gAdj[u].push_back(v);
        gAdj[v].push_back(u);
    }
    eulerOrder.clear();
    timer = 0;
    dfsEuler(1, -1);
    
    vector<pair<long long,int>> nodes; 
    nodes.reserve(n);
    for(int i=1; i<=n; i++){
        nodes.push_back({gVal[i], i});
    }
    sort(nodes.begin(), nodes.end(), [&](auto &a, auto &b){
        return a.first > b.first;
    });

    vector<int> status(n+1, -1);

    Fenwick fenwTotal(n);  
    Fenwick fenwLosing(n); 

    
    int i = 0;
    
    long long maxVal = nodes[0].first;
    while(i < n && nodes[i].first == maxVal){
        int nd = nodes[i].second;
        status[nd] = 0;  
        int pos = gIn[nd]; 
        fenwTotal.update(pos, 1);
        fenwLosing.update(pos, 1);
        i++;
    }

    int winningNode = 0; 

    vector<int> winningnodessall;


    while(i < n){
        long long curVal = nodes[i].first;
        vector<int> sameValNodes;
        long long saveVal = curVal;
        while(i < n && nodes[i].first == saveVal){
            sameValNodes.push_back(nodes[i].second);
            i++;
        }

        for(int nd : sameValNodes){
            int L = gIn[nd], R = gOut[nd];
            int totalBigger = fenwTotal.query(n-1); 
            int totalBiggerInSubtree = fenwTotal.rangeQuery(L, R);
            int outsideTotal = totalBigger - totalBiggerInSubtree;

            int losingBigger = fenwLosing.query(n-1);
            int losingBiggerInSubtree = fenwLosing.rangeQuery(L, R);
            int outsideLosing = losingBigger - losingBiggerInSubtree;

            if (outsideTotal == outsideLosing && outsideTotal > 0) {
                winningNode = nd;
                winningnodessall.push_back(nd);
            }
            else {
                status[nd] = 0;
            }
        }
        
        for(int nd: sameValNodes){
            
            if(status[nd] == -1){
                status[nd] = 0;
            }
            int pos = gIn[nd];
            fenwTotal.update(pos, 1);
            if(status[nd] == 0){
                fenwLosing.update(pos, 1);
            }
        }
    }

    sort(winningnodessall.begin(), winningnodessall.end());

    if(winningNode == 0) {
        cout << 0 << "\n";
    }
    else {
        cout << winningnodessall.size() <<" ";
        for(int nd: winningnodessall){
            cout << nd << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;
    while(t--){
        solveOneTest();
    }
    return 0;
}