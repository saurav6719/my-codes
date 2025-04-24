/**
 *    author: Saurav
 *    created: 2024.10.25 17:06:43
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

int dp[101][10001];
int f(int i, int j , vector<vector<int> > &input, vector<vector<int> > &precompute){
    // ith row se utha rhe hai j remaining items hai 

    // ith row se hum 0 se leke min(input[i].size , j) tak utha skte hai

    if(i == input.size()){
        if(j > 0) return -1e12;
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];



    int ans = 0;

    for(int u = 0; u<= min(j, (int) input[i].size()); u++){
        ans = max(ans, precompute[i][u] + f(i+1,j-u,input,precompute));
    }

    return dp[i][j] = ans;
}
void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int> > v(n,vector<int> ());

    for(int i = 0; i<n; i++){
        int sz;
        cin>>sz;
        for(int j =0; j<sz; j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }

    memset(dp,-1,sizeof(dp));

    vector<vector<int> > precompute(101, vector<int> (101,0));
    // agar ith row me j elements uthaye to max profit kya hoga 

    for(int i = 0; i<n; i++){
        vector<int> prfsum(v[i].size()+1,0);
        for(int j = 0; j<v[i].size(); j++){
            prfsum[j+1] = prfsum[j] + v[i][j];
        }

        print(prfsum);

        vector<int> suffsum(v[i].size()+1,0);
        for(int j = v[i].size()-1; j>=0; j--){
            suffsum[j] = suffsum[j+1] + v[i][j];
        }

        print(suffsum);

        for(int j = 0; j<=v[i].size(); j++){

            int maxi = prfsum[j];
            // if(i==0 and j==3) debug(maxi);
            int kk = j;
            int ll = v[i].size();

            while(kk>=0){

                

                int curr = prfsum[kk] + suffsum[ll];
                maxi = max(maxi,curr);

                // if(i==0 and j==3){
                //     debug(kk);
                //     debug(ll);
                //     debug(prfsum[kk]);
                //     debug(suffsum[ll]);
                //     debug(maxi);
                //     debug(curr);
                // }


                kk--;
                ll--;
            }
            precompute[i][j] = maxi;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=v[i].size(); j++){
            debug(i);
            debug(j);
            debug(precompute[i][j]);
        }
    }

    cout<<f(0,m,v,precompute)<<endl;


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

