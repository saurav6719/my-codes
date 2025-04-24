/**
 *    author: Saurav
 *    created: 2024.10.28 17:51:14
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
    int n;
    cin>>n;

    vector<vector<int> > grid(n+1, vector<int> (n+1)) ;

    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            cin >> grid[i][j] ;
        }
    }

    int sum = 0;
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            sum += grid[i][j] ;
        }
    }

    debug(sum);

    int q;
    cin >> q;
    while(q--){
        int c,d;
        cin >> c >> d;
        int l;
        cin >> l;

        int oldcd = grid[c][d] ;
        if(oldcd > l){
            sum -= oldcd;
            grid[c][d] = l;
            sum += l;
            grid[d][c] = l;
        }

        for(int i = 1; i<=n; i++){
            for(int j= i+1; j<=n; j++){
                int a = i;
                int b = j;

                int oldac = grid[a][c] ;
                int newac = grid[a][d] + l;
                if(newac < oldac){
                    sum -= oldac;
                    grid[a][c] = newac;
                    sum += newac;
                    grid[c][a] = newac;
                }

                int oldad = grid[a][d] ;
                int newad = grid[a][c] + l;
                if(newad < oldad){
                    sum -= oldad;
                    grid[a][d] = newad;
                    sum += newad;
                    grid[d][a] = newad;
                }

                int oldbc = grid[b][c] ;
                int newbc = grid[b][d] + l;
                if(newbc < oldbc){
                    sum -= oldbc;
                    grid[b][c] = newbc;
                    sum += newbc;
                    grid[c][b] = newbc;
                }

                int oldbd = grid[b][d] ;
                int newbd = grid[b][c] + l;
                if(newbd < oldbd){
                    sum -= oldbd;
                    grid[b][d] = newbd;
                    sum += newbd;
                    grid[d][b] = newbd;
                }

                int oldab = grid[a][b] ;
                int newab1 = grid[a][c] + grid[c][b] ;
                int newab2 = grid[a][d] + grid[d][b] ;
                int newab = min(newab1,newab2) ;
                if(newab < oldab){
                    sum -= oldab;
                    grid[a][b] = newab;
                    sum += newab;
                    grid[b][a] = newab;
                }
            }
        }
        
        cout<<sum<<" ";
    }
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

