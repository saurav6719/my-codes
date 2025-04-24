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
    return parent[x] == x ? x : find(parent, parent[x]);
}

void Union(vector<int> &parent,vector<int> &rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}


void solve(){
    int n;
    cin>>n;
    vector<int> input(n+1);
    map<int,int> mp;
    for(int i = 1; i<=n; i++){
        cin>>input[i];
        mp[input[i]]++;
    }

    vector<int> input_copy =input;


    
    // int root = -1;
    // int curr = 0;

    // for(auto ele : mp){
    //     if(ele.second > curr){
    //         root = ele.first;
    //         curr = ele.second;
    //     }
    // }


    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i = 0; i<=n ; i++){
        parent[i] = i;
    }

    // debug(root);
    vector<int> possible_roots;
    for(int i = 1; i<=n; i++){
        int ele = i;
        int par = input[i];
        if(find(parent, ele) == find(parent, par)){
            possible_roots.push_back(ele);
        }
        else{
            Union(parent, rank, ele, par);
        }
    }

    print(possible_roots);

    if(possible_roots.size() == 0){
        cout<<0<<endl;
        for(int i = 1; i<=n; i++){
            cout<<input[i]<<" ";
        }

        return;
    }

    int root = -1;

    for(auto ele : possible_roots){
        if(input[ele] == ele){
            root = ele;
            break;
        }
    }

    if(root == -1){
        root = possible_roots[0];
    }

    int ans = 0;

    for(auto ele : possible_roots){
        int currpar = input[ele];
        int newpar = root;
        if(currpar != newpar) ans++;
        input[ele] = newpar;
    }

    

    

    // int ans = 0;

    // for(int i = 1; i<=n; i++){
    //     if(input[i] != input_copy[i]){
    //         ans++;
    //     }
    // }

    cout<<ans<<endl;
    
    for(int i = 1; i<=n; i++){
        cout<<input[i]<<" ";
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

