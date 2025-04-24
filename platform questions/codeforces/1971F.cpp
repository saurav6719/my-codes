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

int equdis(int x, int y){
    int xx = x*x;
    int yy = y*y;

    xx+=yy;
    return sqrt(xx);
}

bool poss(int mid, int r, int i){
    return (((mid * mid) + (i*i)) < (r*r));
}

bool poss2(int mid, int r, int i){
    return (((mid * mid) + (i*i)) >= (r*r));
}


void solve(){
    int r;
    cin>>r;

    if(r==1){
        cout<<8<<endl;
        return;
    }

    vector<int> one;

    for(int i = 1; i<=r; i++){
        int xx = i*i;

        // finding max number which i can take 
        int lo = 1;
        int hi = r;
        int res = -1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(poss(mid, r+1, i)){
                res = mid;
                lo = mid +1;
            }
            else hi = mid -1;
        }

        debug(res);
        one.push_back(res);
    }

    vector<int> two;

    for(int i = 1; i<=r; i++){
        int xx = i*i;

        // finding min number which i can take 
        int lo = 1;
        int hi = r;
        int res = -1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(poss2(mid, r, i)){
                res = mid;
                hi = mid -1;
            }
            else lo = mid +1;
        }

        debug(res);
        two.push_back(res);
    }

    print(one);
    print(two);

    int cnt = 0;
    for(int i = 0; i<r; i++){
        cnt+= one[i] - two[i] + 1;
    }
    cnt *= 4;
    cnt += 4;

    cout<<cnt<<endl;
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

