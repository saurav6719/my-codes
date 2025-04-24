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

bool poss(int mid, int l, int r, int sz, int tomul2){
    if(mid * tomul2 * 3 <= r)  return true;
    return false;
}

bool poss2(int mid, int l, int r, int sz, int tomul){
    if(mid * tomul <= r) return true;
    return false;
}
void solve(){
    int l;
    cin>>l;
    int r;
    cin>>r;

    int l_copy = l;
    int sz = 0;
    while(l_copy <= r){
        sz++;
        l_copy *= 2;
    }

    cout<<sz<<" ";

    int tomul = (1<<sz-1);

    int tomul2 = (1<<sz-2);

    int secondans = 0;


    int lo = l;int hi = r;

    int res = -1;

    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(poss(mid, l, r, sz, tomul2)){
            res = mid;
            lo = mid + 1 ;
        }
        else hi = mid - 1;
    }



    int cnt = (res - l + 1);
    if(res == -1) {
        cnt = 0;
        res = l;
    }
    debug(cnt);

    debug(res);

    secondans += (cnt * sz);

    debug(secondans);

    int lo2 = res;int hi2 = r;

    int res2 = -1;

    while(lo2 <= hi2){
        int mid = (lo2 + hi2) / 2;
        if(poss2(mid, l, r, sz, tomul)){
            res2 = mid;
            lo2 = mid + 1 ;
        }
        else hi2 = mid - 1;
    }
    debug(res2);

    if(secondans == 0) secondans++;

    secondans += (res2 - res );

    



    // for(int i = l ;i<=r; i++){
    //     if(i * tomul <= r){
    //         if(i * tomul2 * 3 <= r){
    //             secondans += sz;
    //         }
    //         else secondans++;
    //     }
    //     else break;
    // }

    cout<<secondans;
    cout<<endl;
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

