// /*
//   ------------------------------------------
//  |                                        |
//  |      Code Crafted by Saurav     |
//  |                                        |
//   ------------------------------------------
//     \        ,     ,        /
//       \      |     |      /
//          \   \___/   /
//            \  -----  /
//              \_____/
  
//   Happy coding! 
// */

// /* includes and all */

// #include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
// #define print(v) do { \
//                     cout << "vect--" << #v << " = [ "; \
//                     for (int i = 0; i < v.size(); i++) { \
//                         cout << v[i] << " "; \
//                     } \
//                     cout << " ]" << endl; \
//                 } while(0)
// #else
// #define debug(x)
// #define print(v)
// #endif
// #define endl "\n"
// #define int long long int
// #define mod 1000000007
// #define mn(a,b,c) min(a,min(b,c))
// #define mx(a,b,c) max(a,max(b,c))
// using namespace std;

// /* write core logic here */
// int n;
// int x;
// vector<int> dp;
// vector<int> prices;
// vector<int> pages;
// int f(int j){
//     for(int i = n-1;i>=0; i--){
//         for(int j = x; j>=0;j--){
//             dp[j] = max(dp[j] , (j>= prices[i]) ? dp[j - prices[i]] + pages[i] : INT_MIN);
//         }
//     }
//     return dp[j];
// }

// void solve(){
//     cin>>n;
//     cin>>x;
//     pages.resize(n);
//     prices.resize(n);
//     dp.clear();
//     dp.resize(x+5,0);
//     for(int i= 0;i<n; i++){
//         cin>>prices[i];
//     }
//     for(int i = 0; i<n; i++){
//         cin>>pages[i];
//     }
//     cout<<f(x);
    
    
// }
// /* logic ends */

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt" , "w" , stderr);
//     #endif
//     int t;
//     //cin>>t;
//     t = 1;
//     while(t--){
//         solve();
//     }
// return 0;
// }



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

//vector<vector<int> >dp;
// //int f(int n,int x, vector<int> &cost, vector<int>&pages, int i, int j){
//     //base case 
//     if(i==n-1){
//         if(j+cost[i] <= x){
//             return dp[i][j] = pages[i];
//         }
//         else return dp[i][j] = 0;
//     }
//     if(j>x) return 0;
//     //if(i>=n) return INT_MIN;
//     if(dp[i][j] != -1) return dp[i][j];
//     return dp[i][j] = max(f(n,x,cost,pages,i+1,j) , (j+cost[i] <=x) ? f(n,x,cost,pages,i+1,j+cost[i]) + pages[i] : 0);
// }
void solve(){
    int n;
    int x;
    cin>>n>>x;
    vector<int> cost(n);
    vector<int> pages(n);
    for(int i = 0; i<n; i++){
        cin>>cost[i];
    }
    for(int j = 0; j<n; j++){
        cin>>pages[j];
    }
    vector<int> next(x+1, 0);
    for(int i = 0 ; i<=x; i++){
        if(i + cost[n-1] <= x) next[i] = pages[n-1];
    }
    for(int i = n-2; i>=0; i--){
        vector<int> current(x+1, 0);
        for(int j = x; j>=0;j--){
            int pick = 0;
            int skip = next[j];
            if(j+cost[i] <= x){
                pick = next[j+cost[i]] + pages[i];
            }
            current[j] = max(pick,skip);
        }
        next = current;
    }
    cout<<next[0];
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}



