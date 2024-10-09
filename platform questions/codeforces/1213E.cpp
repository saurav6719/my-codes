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
    int m;
    cin>>n>>m;
    vector<vector<pp>> input(200006);

    vector<int> v;
    set<int> stl;
    for(int i = 0; i<n-1; i++){
        int a,b,w;
        cin>>a>>b>>w;

        input[w].push_back({a,b});
        
        stl.insert(w);
    } 

    for(auto ele : stl){
        v.push_back(ele);
    }

    sort(v.begin(), v.end());

    print(v);

    vector<int> parent(n+1);
    vector<int> size(n+1,1);
    for(int i = 0; i<=n ; i++){
        parent[i] = i;
    }

    vector<int> ans(200006, 0);
    int curr = 0;

    set<int> st;

    int currtotal = 0;

    for(int i = 1; i<=200005; i++){
        for(auto ele : input[i]){
            int a = ele.first;
            int b = ele.second;
            debug(a);
            debug(b);
            a = find(parent, a);
            b = find(parent , b);

            int sizea = size[a];
            int sizeb = size[b];

            currtotal += (sizea * sizeb);
            Union(parent , size, a, b);
        }
        ans[i] = currtotal;
    }

    while(m--){
        int a;
        cin>>a;


        if(v.empty()){
            cout<<0<<" ";
            continue;
        }

        if(a<v[0]){
            cout<<0<<" ";
            continue;
        }

        int xx = upper_bound(v.begin(), v.end(), a)- v.begin();
        xx--;

        xx = v[xx];

        

        // if(xx == v.size()) xx = v.back();
        // else if(v[xx] > a){
        //     xx--;
        //     xx = v[xx];
        // }
        // else xx = v[xx];

        // debug(a);
        // debug(xx);

        cout<<ans[xx]<<" ";
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

