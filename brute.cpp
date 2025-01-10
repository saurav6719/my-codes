/**
 *    author: Saurav
 *    created: 2025.01.11 01:05:52
 **/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void  bfs(vector<vector<int> > &graph, int source, vector<int> &dist, vector<pp> &highs){
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    pp first = {-1,-1};
    pp second = {-1,-1};
    pp third = {-1,-1};
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child : graph[node]){
            if(dist[child] == -1){
                dist[child] = dist[node] + 1;
                q.push(child);
                third = second;
                second = first;
                first = {dist[child],child};
            }
        }
    }
    if(first.first != -1) highs.push_back(first);
    if(second.first != -1)highs.push_back(second);
    if(third.first != -1) highs.push_back(third);

    return;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n);
    vector<vector<int> > reverse_graph(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }

    vector<vector<int> > dist(n, vector<int> (n, -1));
    vector<vector<int> > reversedist(n, vector<int> (n, -1));
    vector<vector<pp> > mainhigh(n, vector<pp> ());
    vector<vector<pp> > reversehigh(n, vector<pp> ());



    for(int i=0;i<n;i++){
        bfs(graph,i, dist[i], mainhigh[i]);
        bfs(reverse_graph,i, reversedist[i], reversehigh[i]);
    }

    int finalans = -1e15;
    int finala = -1;
    int finalb = -1;
    int finalc = -1;
    int finald = -1;

    for(int b = 0; b<n; b++){
        for(int c = 0; c<n; c++){
            unordered_set<int> st;
            st.insert(b);
            st.insert(c);
            for(auto ele1 : reversehigh[b]){
                for(auto ele2 : mainhigh[c]){
                    int a = ele1.second;
                    int d = ele2.second;

                    st.insert(a);
                    st.insert(d);

                    if(st.size() < 4)  continue;
                    if(dist[a][b] == -1 || dist[b][c] == -1 || dist[c][d] == -1) continue;

                    int length = dist[a][b] + dist[b][c] + dist[c][d];
                    if(length > finalans){
                        finalans = length;
                        finala = a;
                        finalb = b;
                        finalc = c;
                        finald = d;
                    }
                }
            }
        }
    }

    cout<<finala+1<<" "<<finalb+1<<" "<<finalc+1<<" "<<finald+1<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

