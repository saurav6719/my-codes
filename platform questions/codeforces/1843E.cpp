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
struct segments{
    int l;
    int r;
    int sum;
};


bool poss(int mid, vector<segments> &v, vector<int> arr, vector<int> &queries){
    // if(mid > queries.size() )return false;
    
    
    // pri/nt(queries);
    int xx = min((int)mid, (int)(queries.size()));
    for(int i = 0; i<xx; i++){
        // debug(queries[i]-1);
        arr[queries[i]-1]++;
    }
    for(int i = 1; i<arr.size(); i++){
        arr[i] += arr[i-1];
    }
    // debug(mid);
    // debug(xx);
    // print(arr);
    for(auto ele : v){
        int l = ele.l;
        int r = ele.r;
        l--;
        r--;
        int size = r-l+1;
        int sum = arr[r] - ((l>0) ? arr[l-1] : 0);
        if(sum > size/2) return true;
    }
    return false;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n, 0);
    vector<segments> v(m);

    for(int i = 0; i<m; i++){
        cin>>v[i].l>>v[i].r;
        v[i].sum = 0;
    }
    int q;
    cin>>q;

    vector<int> queries(q);
    for(int i = 0; i<q; i++){
        cin>>queries[i];
    }

    int lo = 0;
    int hi = n;
    int res= -1;
    while(lo<=hi){
        int mid = (lo + hi )/ 2;

        if(poss(mid,v, arr, queries)){
            hi = mid-1;
            res = mid;
        }
        else lo =mid + 1;

    }

    cout<<res<<endl;




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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

