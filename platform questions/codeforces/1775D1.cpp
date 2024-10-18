#include<bits/stdc++.h>
#define int long long
using namespace std;

/* Helper function to get all unique prime factors of a number */
vector<int> getPrimeFactors(int num) {
    vector<int> factors;
    if (num < 2) return factors;
    // Handle 2 separately
    if (num % 2 == 0) {
        factors.push_back(2);
        while (num % 2 == 0) num /= 2;
    }
    // Check for odd factors
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            factors.push_back(i);
            while (num % i == 0) num /= i;
        }
    }
    // If remaining num is a prime
    if (num > 2) factors.push_back(num);
    return factors;
}

/* BFS-based shortest path using prime factor mapping */
void solve(){
    int n;
    cin >> n;
    
    vector<int> input(n);
    for(auto &x : input) cin >> x;
    
    int s, t;
    cin >> s >> t;
    s -= 1; // Convert to 0-based index
    t -= 1;
    
    // Edge case: start and end are the same
    if(s == t){
        cout << "1\n" << s+1 << "\n";
        return;
    }
    
    // Find the maximum number to determine the range of primes
    int max_num = 0;
    for(auto &x : input) max_num = max(max_num, x);
    
    map<int, vector<int>> prime_map;

    for(int i = 0; i<n; i++){
        vector<int> pf = getPrimeFactors(input[i]);
        for(auto &x : pf) prime_map[x].push_back(i);
    }

    // BFS
    queue<int> q;
    vector<int> visited(n+1, -1);
    vector<int> parent(n+1, -1);
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u==t){
            break;
        }
        vector<int> pf2 = getPrimeFactors(input[u]);
        for(auto x : pf2){
            for(auto v : prime_map[x]){
                if(visited[v] == -1){
                    visited[v] = 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
            prime_map[x].clear();
        }
    }

    if(parent[t] == -1){
        cout << "-1\n";
        return;
    }

    vector<int> path;
    int curr = t;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }

    cout << path.size() << "\n";
    for(int i = path.size()-1; i>=0; i--){
        cout << path[i]+1 << " ";
    }
    cout << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}