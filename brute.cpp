/**
 *    author: Saurav
 *    created: 2024.12.28 20:35:27
 **/

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
long long sumOfAP(long long a, long long d, long long n) {
    // Calculate sum using the formula
    return n * (2 * a + (n - 1) * d) / 2;
}
void solve(){
    int n,k;
    cin>>n>>k;
    int currl = 1;
    int currr = n;

    int currterms = 1;

    int ans = 0;
    bool lasteven = false;
    if(n % 2 == 0){
        lasteven = true;
    }
    while(currr >= k){

        // debug(currr);
        int size = currr - currl + 1;
        if(size % 2 == 0){
            int m = (currl + currr) / 2;
            currr = m;
            currterms *= 2;
            lasteven = true;
            continue;
        }
        else{
            int curra = (currl + currr) / 2;
            debug(curra);
            int d;
            if(lasteven){
                d = size;
            }
            else d = size+1;
            debug(d);
            debug(currterms);
            ans += sumOfAP(curra,d,currterms);
            debug(ans);
            currterms *= 2;
            currr = ((currl + currr) / 2) - 1;
            lasteven = false;
        }
        // debug(ans);
        // debug(currr);
    }

    // 1 - 725 // 363
    // 726 - 1450//1088

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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

