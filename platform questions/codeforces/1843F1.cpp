/**
 *    author: Saurav
 *    created: 2024.10.23 21:18:58
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
    int n;
    cin>>n;
    int currsize = 1;
    vector<int> maxending(n+2,0);
    vector<int> minending(n+2,0);
    maxending[1] = 1;
    minending[1] = 0;
    vector<int> maxres(n+2,0);
    vector<int> minres(n+2,0);
    maxres[1] = 1;
    minres[1] = 0;
    for(int i = 0; i<n; i++){
        char ch;
        cin>>ch;
        if(ch == '+'){
            int par;
            cin>>par;
            currsize++;

            int curr;
            cin>>curr;

            int parmaxi = maxending[par];

            int maxi = max(maxending[par] + curr , curr);
            maxi = max(maxi , 0ll);

            maxending[currsize] = maxi;

            maxres[currsize] = max(maxres[par] , maxi);

            int parmini = minending[par];

            int mini = min(minending[par] + curr , curr);
            mini = min(mini , 0ll);

            minending[currsize] = mini;

            minres[currsize] = min(minres[par] , mini);
        }
        else{
            int x,y;
            cin>>x>>y;
            int mini = minres[y];
            int maxi = maxres[y];

            int val;
            cin>>val;

            if(mini <= val and val <= maxi){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

