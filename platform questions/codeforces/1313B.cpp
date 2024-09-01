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
int f1(int n, int a,int b){
    int sum = a+b;
    int last = n;
    int start = 1;
    int toadd = n;
    if(toadd == b) toadd--;
    if(start == a) start++;
    int ans1 = -1;
    int ans2 = -1;

    int lo = start;
    int hi = last ;

    debug(start);debug(last);
    int res = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int xx = mid;
        int yy = toadd;
        if(xx+yy > sum){
            res = mid;
            hi = mid - 1;
        }
        else {
            lo = mid +1;
        }
    }
    debug(res);

    if(res==-1){
        return n;
    }

    int kitneupr = res-1;
    debug(kitneupr);
    if(kitneupr >= a){
        kitneupr--;
    }
    ans1 = kitneupr+1;

    return ans1;
}

int f2(int n, int a, int b){
    //last number jisme start add kre to less than equal to sum aaye 

    int sum = a+b;
    int start = 1;
    int toadd = 1;
    if(toadd == b) toadd++;
    debug(toadd);
    if(start == a) start++;
    int last = n;
    int lo = start;
    int hi = last;
    debug(lo);
    debug(hi);
    int res = -1;
    while(lo<=hi){
        int mid= (lo + hi)/2;
        if(mid + toadd <= sum){
            res = mid;
            lo = mid+1;
        }
        else hi = mid - 1;
    }

    if(res==-1){
        return 1;
    }

    int kitneupr = res;
    debug(kitneupr);
    if(a > kitneupr){
        kitneupr++;
    }


    int ans2 = kitneupr;
    debug(kitneupr);

    return ans2;
}
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int x = f2(n,a,b);
    int y = f1(n,a,b);
    debug(x);
    cout<<y<<" "<<x<<endl;
    

    

    




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
    // t = 1;it n,a,b;
    while(t--){
        solve();
    }
return 0;
}

