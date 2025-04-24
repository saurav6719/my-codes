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

pair<int,int> Get(vector<int> &parent, int a, vector<int> &parity){
    //this function will return parent as well as parity 
    if(parent[a] == a){
        return {a,0};
    }

    pair<int,int> xx = Get(parent, parent[a], parity);
    parent[a] = xx.first;
    parity[a] = (parity[a] + xx.second) % 2; 
    return {parent[a], parity[a]};
}

void Union(vector<int> &parent, vector<int> &parity, int a , int b, vector<int> &size){
    pair<int,int> aa = Get(parent,a, parity);
    pair<int,int> bb = Get(parent,b, parity);

    if(size[aa.first] > size[bb.first]){
        swap(aa, bb);
    }
    parent[aa.first] = bb.first;
    parity[aa.first] =( 1 + parity[aa.second] + parity[bb.second] ) % 2;
    size[bb.first] += size[aa.first];
} 

void solve(){

    int n;
    cin>>n;
    vector<int> parity(n+1, 0);
    vector<int> parent(n+1);
    for(int i =0 ;i <=n; i++){
        parent[i] = i;
    }

    vector<int> size(n+1, 1);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        int a;
        int b;
        cin>>a>>b;
        if(type == 1){
            Union(parent, parity, a, b, size);
        }
        if(type == 2){
            pair<int, int> xx = Get(parent, a, parity);
            pair<int, int> yy = Get(parent, b, parity);

            if(xx.second == yy.second){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

