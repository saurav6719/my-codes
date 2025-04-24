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

int get(int x , vector<int> &parent){
    if(parent[x] == x) return x;
    return get(parent[x], parent);
}

void Union(int left , int right, vector<int> &parent){
    left = get(left, parent);
    right = get(right, parent);
    parent[left] = right;
}
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int> parent(n+5);
    for(int i = 0; i<n+5; i++){
        parent[i] = i;
    }

    while(m--){
        char ch;
        cin>>ch;
        if(ch == '-'){
            int ele;
            cin>>ele;
            Union(ele, ele+1, parent);
        }

        else{
            int ele ;
            cin>>ele;
            int res = get(ele, parent);
            if(res == n+1){
                cout<<-1<<endl;
                return;
            }
            else cout<<res<<endl;
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

