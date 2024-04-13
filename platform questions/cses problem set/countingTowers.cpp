/*
    ------------------------------------------
    |                                        |
    |      Code Crafted by Saurav     |
    |                                        |
    ------------------------------------------
        \        ,     ,        /
        \      |     |      /
            \   \___/   /
            \  -----  /
                \_____/
    
    Happy coding! 
    */
 
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
    #else
    #define debug(x)
    #define print(v)
    #endif
    #define endl "\n"
    #define int long long int
    #define mod 1000000007
    #define mn(a,b,c) min(a,min(b,c))
    #define mx(a,b,c) max(a,max(b,c))
    using namespace std;
 
    /* write core logic here */

    vector<vector<int> > dp(1e6+1,vector<int> (2));
    map<int,int> mp;

    void solve(){
        int n;
        cin>>n;
        if(mp.count(n)){
            cout<<mp[n]<<endl;
            return;
        }
        dp[n-1][0] = 1;
        dp[n-1][1] = 1;
        for(int i = n-2; i>=0;i--){
            dp[i][0] = ((4%mod * dp[i+1][0]%mod)%mod + dp[i+1][1] % mod)%mod;
            dp[i][1] = ((2%mod * dp[i+1][1]%mod)%mod + dp[i+1][0] % mod) % mod;
        }
 
        int ans = (dp[0][0] % mod + dp[0][1] % mod)%mod;
        cout<<ans<<endl;
        mp[n] = ans;
 
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
