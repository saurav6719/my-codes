/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

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

void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<map<int,int> > mp(n+1);
    vector<int> parent(n+1);
    vector<int> size(n+1,1);
    for(int i = 0; i<=n ; i++){
        parent[i] = i;
    }
        int cnt=0;
    for(int i = 0; i<m; i++){
        int a,d,k;
        cin>>a>>d>>k;
        int currstart = a;
        int currend  = a + k*d;
        debug(currend);
        debug(currstart);
        int j = currstart;
        while(j<=currend){
            if(mp[j].count(d)){
                int thatend = mp[j][d];
                mp[j][d] = max(currend, thatend);
                if(currend > thatend){
                    j = thatend + d;
                    Union(parent,size,currend,j);
                    Union(parent,size,currstart,j); 
                    Union(parent,size,currend,thatend);
                    Union(parent,size,currstart,thatend);
                    continue;
                }
                else{
                    Union(parent,size,currend,j);
                    Union(parent,size,currstart,j);
                    break;
                }
            }
            else{
                mp[j][d] = currend;
                Union(parent,size,currend,j);
                Union(parent,size,currstart,j);
            }
            j+=d;
        }
    }
    print(parent);
    //now i need to find number of connected components 
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(parent[i] == i){
            ans++;
        }
    }
    cout<<ans<<endl;
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

