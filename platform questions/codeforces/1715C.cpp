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
    int q;
    cin>>q;
    vector<int> input(n);
    for(int i= 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> dp(n);

    int sum = 1;
    // int curr = 1;

    dp[0] = 1;
    for(int i = 1 ; i<n; i++){
        if(input[i] != input[i-1]){
            sum += dp[i-1] + 1;
            dp[i] = dp[i-1] + 1;
        }
        else{
            sum += dp[i-1];
            dp[i] = dp[i-1];
        }
    }

    

    int ans = sum;

    dp[0] = sum;

    debug(dp[0]);



    for(int i = 1; i<n; i++){
        if(input[i] == input[i-1]){
            dp[i] = dp[i-1] - 1;
        }
        else dp[i] = dp[i-1] - (n-i+1); //6-1-
    }

    ans = 0;

    for(int i = 0; i<n; i++){
        ans += dp[i];
    }



    print(dp);

    // cout<<ans<<endl;

    debug(ans);


    while(q--){
        int index;
        int value;
        cin>>index>>value;  
        index--;

        int right = 0;
        int prevcurr = input[index];
        int currval = value;

        debug(prevcurr);
        debug(currval);

        input[index] = value;

        if((index + 1)< n and prevcurr == input[index +1] and currval != input[index + 1]){
            right += (n-1-index);
            ans += right;
            debug(right);
        }
        else if((index + 1)< n and prevcurr != input[index +1] and currval == input[index + 1]){
            right -= (n-1-index);
            ans += right;
            debug(right);
        }

        int left = 0;
        left += right;
        debug(left);

        if(index>0 and prevcurr == input[index -1] and currval != input[index-1]){
            debug(left);
            int xx = left + (n-1 - index + 1);
            debug((n-1 - index + 1));
            debug(xx);

            xx *= index;
            debug(xx);
            ans += xx;
        }

        else if(index>0 and prevcurr != input[index -1] and currval == input[index-1]){
            debug(ans);
            debug(left);
            debug((n-1 - index + 1));
            int xx = left - (n-1 - index + 1);

            xx *= index;
            ans += xx;
        }
        else if(index>0 and prevcurr != input[index -1] and currval != input[index-1]){
            int xx = left * index;
            ans += xx;
        }

        // ans += left;
        cout<<ans<<endl;
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
    // cin>>t;/
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

