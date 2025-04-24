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

bool poss(int mid, int psum, int to_reduce, int i, int back){
    // if(mid==-2 and i==3) {
    //     debug(mid);debug(psum);debug(to_reduce); debug(back);
    //     debug((psum - (mid * (i+1)) + back - mid));

    // }
    if(back - mid >= to_reduce) return true;
    if(psum - (mid * (i+1)) >= to_reduce) return true;
    
    if((psum - (mid * (i+1)) + back - mid) >= to_reduce) {
        return true;
    }
    return false;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    sort(input.begin(), input.end(), greater<int> ());

    vector<int> prf(n);
    prf[0] = input[0];
    for(int i= 1; i<n; i++){
        prf[i] = prf[i-1] + input[i];
    }

    print(input);

    int sum = prf[n-1];
    int to_reduce = sum - k;

    if(to_reduce <= 0){
        cout<<0<<endl;
        return;
    }
    if(n==1){
        cout<<to_reduce<<endl;
        return;
    }

    int ans = to_reduce;

    for(int i = 0; i<n-1; i++){
        int psum = prf[i];
        int xx = -1e16 / i+1;
        int yy = -2e14;
        int lo = max(xx,yy);
        int hi = input.back();
        int res = -1;
        while(lo <= hi){
            int mid = (lo + (hi-lo)/2);
            if(i==3 and mid==-2) debug(poss(mid, psum, to_reduce, i, input.back()));

            if(poss(mid, psum, to_reduce, i, input.back())){
                res = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        if(i==3) debug(res);
        int total = 0;
        total += i+1;
        total += input.back() - res;
        ans = min(ans , total);
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

