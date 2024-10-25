/**
 *    author: Saurav
 *    created: 2024.10.25 13:29:21
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

struct node{
    bool poss;
    int sum;
};
node dp[101][101][901];

char dp2[101][101];

int dpmain[101][101];


int ans = -1;

pair<bool, int>  f(int i, int j, int currsum , vector<vector<int> > &input, int k){
    if(i<0){
        if(currsum % k == 0){
            return {true,currsum};
        }
        return {false,-1e12};
    }

    if(dp[i][j][currsum].poss != false){
        
        return {dp[i][j][currsum].poss,dp[i][j][currsum].sum};
    }

    if(dp[i][j][currsum].poss == false){
        if(dp[i][j][currsum].sum != -1){
            debug(i);
            debug(j);
            debug(currsum);
            return {false,-1e12};
        }
    }

    bool &poss = dp[i][j][currsum].poss;
    int &sum = dp[i][j][currsum].sum;

    // go upleft
    bool leftfalse = false;
    bool rightfalse = false;
    if(j-1 >= 0){
        auto xx = f(i-1,j-1,currsum+input[i][j],input,k);
        if(xx.first){
            poss = true;
            if(sum < xx.second){
                sum = xx.second;
            }
            if(xx.second > dpmain[i][j]){
                dpmain[i][j] = xx.second;
                dp2[i][j] = 'L';
            }
        }
        else{
            leftfalse = true;
        }
    }

    // go upright

    if(j+1 < input[0].size()){
        auto xx = f(i-1,j+1,currsum+input[i][j],input,k);
        if(xx.first){
            poss = true;
            if(sum < xx.second){
                sum = xx.second;
            }
            if(xx.second > dpmain[i][j]){
                dpmain[i][j] = xx.second;
                dp2[i][j] = 'R';
            }
        }
        else{
            rightfalse = true;
        }
    }

    if(leftfalse and rightfalse){
        poss = false;
        sum = -1e12;
    }

    return {poss,sum};
}



void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    k++;

    vector<vector<char> > grid(n,vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j= 0; j<m; j++){
            char ch;
            cin>>ch;
            grid[i][j] = ch;
        }
    }
    vector<vector<int> > input(n,vector<int> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            input[i][j] = grid[i][j] - '0';
        }
    }

    print2d(input);

    memset(dpmain,-1,sizeof(dpmain));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            for(int kl = 0; kl<901; kl++){
                dp[i][j][kl].poss = false;
                dp[i][j][kl].sum = -1;
            }
        }
    }

    for(int i = 0; i<m; i++){
        pair<bool,int> xx = f(n-1,i,0,input,k);
    }

    debug(dp[n-1][2][0].poss);
    debug(dp[1][1][7].poss);

    for(int i = 0; i<m; i++){
        if(dp[n-1][i][0].poss){
            ans = max(ans,dp[n-1][i][0].sum);
        }
    }

    cout<<ans<<endl;

    if(ans != -1){

        int idx = -1;
        for(int i = 0 ; i<m; i++){
            if(dp[n-1][i][0].sum == ans){
                cout<<i+1<<endl;
                idx = i;
                break;
            }
        }

        string path = "";

        int i = n-1;
        int j = idx;
        while(i > 0){
            path += dp2[i][j];
            if(dp2[i][j] == 'L'){
                j--;
            }
            else{
                j++;
            }
            i--;
        }
        cout<<path<<endl;
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

