/**
 *    author: Saurav
 *    created: 2025.02.13 20:40:54
 *    We stop at Candidate Master in 2025
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
int query(int c){
    cout<<"+ "<<c<<endl;
    cout<<flush;
    int x;
    cin>>x;
    return x;
}
void printans(int x){
    cout<<"! "<<x<<endl;
    cout<<flush;
}
void solve(){
    int n;
    cin>>n;
    int curradded = 0;

    int lo = 1;
    int hi = n - 1;
    int ans = -1;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        debug(mid);
        int ifmidthen = mid + curradded;
        debug(ifmidthen);
        int reqtoadd;
        int modd = ifmidthen % n;
        reqtoadd = (n - modd) % n;
        debug(reqtoadd);

        int aanachahiye = (ifmidthen + reqtoadd) / n;
        debug(aanachahiye);

        int aaya = query(reqtoadd);
        debug(aaya);
        curradded += reqtoadd;

        if(aanachahiye == aaya){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    printans(ans);
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

