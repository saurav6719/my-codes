/**
 *    author: Saurav
 *    created: 2025.02.01 17:26:27
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
void solve(){
    int n,r,c;
    cin>>n>>r>>c;

    string str;
    cin>>str;
    str = '#' + str;

    vector<int> south(n+1, 0);
    vector<int> north(n+1, 0);
    vector<int> east(n+1, 0);
    vector<int> west(n+1, 0);

    for(int i = 1; i<=n; i++){
        if(str[i] == 'E'){
            east[i] = 1;
            west[i] = -1;
        }
        if(str[i] == 'N'){
            north[i] = 1;
            south[i] = -1;
        }
        if(str[i] == 'W'){
            west[i] = 1;
            east[i] = -1;
        }
        if(str[i] == 'S'){
            south[i] = 1;
            north[i] = -1;
        }
    }

    for(int i = 1; i<=n; i++){
        south[i] = max(south[i-1] + south[i] , 0ll);
        north[i] = max(north[i-1] + north[i] , 0ll);
        east[i] = max(east[i-1] + east[i] , 0ll);
        west[i] = max(west[i-1] + west[i] , 0ll);
    }

    print(north);
    print(east);

    if(r <= 0 and c <= 0){
        //n w

        int a = abs(r);
        int b = abs(c);

        for(int i = 1; i<=n; i++){
            if(north[i] >= a and west[i] >= b){
                cout<<1;
            }
            else cout<<0;
        }
    }

    else if(r <= 0 and c >= 0){
        // n e

        int a = abs(r);
        int b = abs(c);

        for(int i = 1; i<=n; i++){
            if(north[i] >= a and east[i] >= b){
                cout<<1;
            }
            else cout<<0;
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

