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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */

int find(vector<int> &parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent,parent[x]);
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

    vector<int> parent(n);
    vector<int> rank(n+1,0);

    for(int i = 0; i<n; i++){
        parent[i] = i;
    }
    map<char, int > mp;
    for(int i = 0; i<n; i++){
        string str;
        cin>>str;
        for(int j = 0; j<str.size(); j++){
            if(mp.count(str[j])){
                Union(parent,rank, i, mp[str[j]]);
            }
        }

        for(int j = 0;j<str.size(); j++){
            if(mp.count(str[j]) == 0){
                mp[str[j]] = i;
            }
        }
    }

    set<int> parentss;

    for(int i = 0; i<n; i++){
        int curr = find(parent, i);
        if(parentss.count(curr) == 0){
            parentss.insert(curr);
        }
    }


    cout<<parentss.size()<<endl;


}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

