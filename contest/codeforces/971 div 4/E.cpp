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

long long sumUpTo(long long n) {
    return n * (n + 1) / 2;
}

// Function to calculate the sum of natural numbers from l to r
long long sumInRange(long long l, long long r) {
    return sumUpTo(r) - sumUpTo(l - 1);
}


/* write core logic here */

long long sumOfAP(long long a, long long d, long long n) {
    long long sum = (n * (2 * a + (n - 1) * d)) / 2;
    return sum;
}


void solve(){
    int n,k;
    cin>>n>>k;

    int end = k + n - 1;

    int start = k;

    int startvalue = sumInRange(k+1 , end);
    startvalue = abs(startvalue - start);


    int decstart = (k+1) * 2;
    debug(decstart);
    debug(startvalue);

    // sum of ap whose sum is startvalue close 

    int lo = 0;
    int hi = 1e9;
    int res = -1;
    int currclose = INT_MAX;
    int cnt = 0;
    while(lo<=hi and cnt<50){
        int mid= ((lo+hi )/ 2);
        int xx = sumOfAP(decstart, 2, mid);
        debug(mid);
        debug(xx);
        
        if(xx <= startvalue){
            if(abs(xx-startvalue) < currclose){
                currclose = abs(xx-startvalue);
                res = mid;
            }
            lo = mid+1;
            debug(lo);
        }
        else {
            if(abs(xx-startvalue) < currclose){
                currclose = abs(xx-startvalue);
                res= mid;
            }
            hi = mid-1;
            debug(hi);
        }
        cnt++;
    }

    
    cout<<currclose<<endl;
    return;




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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

