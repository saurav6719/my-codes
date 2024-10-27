/**
 *    author: Saurav
 *    created: 2024.10.26 19:20:49
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
map<pp, int> dp;
int f(int i , int currgcd , vector<int> &length, vector<int> &cost){
    if(currgcd == 1) return 0;

    if( i == cost.size()) return 1e13;

    if(dp.find({i, currgcd}) != dp.end()){
        return dp[{i, currgcd}];
    }

    // take 

    int take = cost[i] + f(i+1, __gcd(currgcd, length[i]) , length, cost);

    int nottake = f(i+1, currgcd , length , cost);

    return dp[{i, currgcd}] = min(take , nottake);
}
void solve(){
    int n;
    cin>>n;
    vector<int> length;
    vector<int> cost;

    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        length.push_back(x);
    }

    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        cost.push_back(x);
    }


    int costy = 1e15;

    for(int i = 0; i<n; i++){
        costy = min(costy , f(i, 0 , length, cost));
    }

    if(costy > 1e12) costy = -1;

    cout<<costy<<endl;


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

