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
int dp[105][(1<<10) + 5];
int f(int mask , int n, vector<vector<int> > &own, int i){
    if(mask == 0) return 1;
    if(i > 100) return 0;
    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = 0;

    ans += f(mask, n, own , i+1);
    ans %= mod;
    for(int j = 0; j<own[i].size(); j++){
        if((1<<own[i][j]) & mask){
            ans += f(mask ^ (1<<own[i][j]) , n, own, i+1);
            ans %= mod;
        }
    }
    ans %= mod;

    return dp[i][mask] = ans;
}
void solve(){
    int n;
    cin >> n; // Number of persons
    cin.ignore(); // Ignore the newline character after the number of persons
    memset(dp, -1, sizeof dp);
    vector<vector<int>> data(n); // 2D vector to store the numbers for each person

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line); // Read the entire line of numbers
        stringstream ss(line); // Create a stringstream from the line
        int num;
        while (ss >> num) {
            data[i].push_back(num); // Read numbers and add to the current person's vector
        }
    }

   vector<vector<int> > own(101, vector<int> ());

   for(int i = 0; i<n; i++){
        for(int j = 0; j<data[i].size(); j++){
            int num = data[i][j];
            own[num].push_back(i);
        }
   }


   cout<<f(((1<<n) -1) ,n, own, 1)<<endl;







    
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

