/**
 *    author: Saurav
 *    created: 2025.03.25 21:19:31
 *    We stop at Candidate Master in 2025
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
void solve(){
    int n,m,d;
    cin>>n>>m>>d;
    vector<vector<char> > grid(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<int> directdp(m, 0);
    vector<int> indirectdp(m, 0);

    for(int i = 0;i<m; i++){
        if(grid[0][i] == 'X'){
            directdp[i] = 1;
        }
        if(i>0) directdp[i] += directdp[i-1];
    }

    for(int i = 0; i<m; i++){
        if(grid[0][i] == 'X'){
            int left = max(0ll, i-d);
            int right = min(m-1, i+d);
            int cnt = directdp[right] - (left>0?directdp[left-1]:0);
            indirectdp[i] = cnt;
        }

        if(i>0) indirectdp[i] += indirectdp[i-1];
    }

    print(directdp);
    print(indirectdp);

    for(int i = 1; i<n; i++){
        vector<int> newdirectdp(m, 0);
        vector<int> newindirectdp(m, 0);
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'X'){
                int left = max(0ll, j-(d-1));
                int right = min(m-1, j+(d-1));
                int cnt = indirectdp[right] - (left>0?indirectdp[left-1]:0);
                newdirectdp[j] = cnt;
            }
            if(j>0) newdirectdp[j] += newdirectdp[j-1];
        }
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'X'){
                int left = max(0ll, j-d);
                int right = min(m-1, j+d);
                int cnt = newdirectdp[right] - (left>0?newdirectdp[left-1]:0);
                newindirectdp[j] = cnt;
            }
            if(j>0) newindirectdp[j] += newindirectdp[j-1];
        }
        directdp = newdirectdp;
        indirectdp = newindirectdp;
    }

    print(directdp);
    print(indirectdp);

    cout<<indirectdp[m-1]<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

