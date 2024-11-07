/**
 *    author: Saurav
 *    created: 2024.11.05 18:46:58
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

bool poss(int mid, map<int,pp> &dp, int x2, int y2, int n){
    int fullcyle = mid / n;
    int rem = mid % n;

    // mid days ke baad ship kaha par hoga 

    int x = dp[rem].first + fullcyle * (dp[n].first - dp[0].first);
    int y = dp[rem].second + fullcyle * (dp[n].second - dp[0].second);

    return abs(x - x2) + abs(y - y2) <= mid;
}
void solve(){
    int x1,y1;
    cin>>x1>>y1;
    int x2,y2;
    cin>>x2>>y2;int n;
    cin>>n;
    vector<char> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    map<int,pp> dp;
    dp[0] = {x1,y1};

    for(int i = 1; i<=n; i++){
        char ch = input[i-1];
        if(ch == 'L') {
            dp[i] = {dp[i-1].first - 1, dp[i-1].second};
        }
        else if(ch == 'R') {
            dp[i] = {dp[i-1].first + 1, dp[i-1].second};
        }
        else if(ch == 'U') {
            dp[i] = {dp[i-1].first, dp[i-1].second + 1};
        }
        else if(ch == 'D') {
            dp[i] = {dp[i-1].first, dp[i-1].second - 1};
        }
    }

    int lo = 0;
    int hi = 1e15;

    int res = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(poss(mid, dp, x2,y2, n)){
            res = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    cout<<res<<endl;

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

