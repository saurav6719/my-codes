/**
 *    author: Saurav
 *    created: 2024.12.08 20:09:28
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

int dp[100005][205][2];
int f(int i, int last , int lastge, vector<int> &input){


    int ans = 0;

    if(i == input.size() - 1){
        if(input[i] != -1){
            if(lastge == 0){
                if(input[i] == last) return 1;
                return 0;
            }   
            if(last >= input[i]){
                return 1;
            }
            return 0;
        }

        if(lastge == 0) return 1;

        for(int j = 1; j<=last; j++){
            ans += 1;
        }

        return ans;
    }   

    if(dp[i][last][lastge] != -1) return dp[i][last][lastge];

    if(input[i] != -1){
        int newlastge = 0;
        if(input[i-1] >= input[i]){
            newlastge = 1;
        }
        return dp[i][last][lastge] = f(i+1, input[i], newlastge, input);
    }

    if(lastge == 1){
        for(int j = 1; j<=200; j++){
            if(last >= j){
                ans += f(i+1, j, 1, input);
            }
            else {
                ans += f(i+1, j, 0, input);
            }
        }
    }

    else{
        for(int j = last; j<=200; j++){
            int newlastge = 0;
            if(j == last) newlastge = 1;
            ans += f(i+1, j, newlastge, input);
        }
    }

    return dp[i][last][lastge] = ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    memset(dp, -1, sizeof(dp));


    int ans = 0;

    if(input[0] != -1){
        ans = f(1, input[0], 0, input);
    }
    else{
        for(int i = 1; i<=200; i++){
            ans += f(1, i, 0, input);
        }
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

