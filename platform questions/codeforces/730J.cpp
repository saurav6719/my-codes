/**
 *    author: Saurav
 *    created: 2024.10.28 18:43:26
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
pp dp[101][10001];
pp f(int idx , vector<int> &a, vector<int> &b, int remaining){
    if(remaining <= 0){
        return {0,0};
    }
    if(idx == a.size()){
        if(remaining <= 0) return {0,0};
        return {1e12, -1e12};
    }

    if(dp[idx][remaining] != pp{-1,-1}){
        return dp[idx][remaining];
    }

    pp ans = {1e12, -1e12};

    //take 

    pp take = f(idx+1, a, b, remaining - b[idx]);
    int takefirst = take.first + 1;
    int takeSecond = take.second + a[idx];

    take = {takefirst, takeSecond};

    //not take

    pp nottake = f(idx+1, a, b, remaining);
    int nottakefirst = nottake.first;
    int nottakeSecond = nottake.second;

    nottake = {nottakefirst, nottakeSecond};

    if(take.first < nottake.first){
        ans = take;
    }
    else if(take.first == nottake.first){
        if(take.second > nottake.second){
            ans = take;
        }
        else{
            ans = nottake;
        }
    }
    else{
        ans = nottake;
    }

    return dp[idx][remaining] = ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int remainingsoda = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        remainingsoda += a[i];
    }
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    for(int i=0;i<101;i++){
        for(int j=0;j<10001;j++){
            dp[i][j] = {-1,-1};
        }
    }

    pp ans = f(0, a, b, remainingsoda);

    cout<<ans.first<<" "<<remainingsoda - ans.second<<endl;


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

