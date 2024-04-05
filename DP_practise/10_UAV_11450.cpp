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
// vector<vector<int> > dp;

// int f(int money , int garment, vector<vector<int> > &input, int k, int m){
//     if(money < 0 ) return INT_MIN;
//     if(garment == k) return m-money;
//     if(dp[money][garment] != -1) return dp[money][garment];
//     int ans = -1;
//     for(int i = 1; i<=input[garment][0]; i++){
//         ans = max(ans, f(money - input[garment][i], garment + 1, input, k ,m));
//     }
//     return dp[money][garment] = ans;
// }

// void solve(){
//     int m;
//     cin>>m;
//     int k;
//     cin>>k;
//     vector<vector<int> > input(k, vector<int> ());
//     for(int i = 0; i<k; i++){
//         int ele;
//         cin>>ele;
//         input[i].push_back(ele);
//         for(int j =1; j<=ele; j++){
//             int xx;
//             cin>>xx;
//             input[i].push_back(xx);
//         }
//     }
//     dp.clear();
//     dp.resize(m+5,vector<int> (k+5,-1));
//     int ans = f(m,0, input, k,m);
//     if(ans >= 0) {
//         cout<<ans<<endl;
//     }
//     else cout<<"no solution"<<endl;
// }
// /* logic ends */

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt" , "w" , stderr);
//     #endif
//     int t;
//     cin>>t;
//     //t = 1;
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
vector<vector<int> > dp;

void f(int m, int k, vector<vector<int> > &input){
    // base case
    for(int j=  1; j<=input[0][0]; j++){
        if(m - input[0][j] >= 0){
            dp[0][m- input[0][j]] = 1;
        }
    }

    print(dp[0]);

    for(int i = 1; i<k; i++){
        for(int j = 1; j<=input[i][0]; j++){
            for(int k = 0;k<=m; k++){
                if(dp[i-1][k] == 1){
                    if(k - input[i][j] >= 0) {
                        dp[i][k - input[i][j]] = 1;
                    }
                }
            }
        }
        print(dp[i]);
    }

    for(int i = 0; i<=m; i++){
        if(dp[k-1][i] == 1){
            cout<<(m-i)<<endl;
            return;
        }
    }
    cout<<"no solution"<<endl;

}
void solve(){
    int m;
    cin>>m;
    int k;
    cin>>k;
    vector<vector<int> > input(k, vector<int> ());
    for(int i = 0; i<k; i++){
        int ele;
        cin>>ele;
        input[i].push_back(ele);
        for(int j =1; j<=ele; j++){
            int xx;
            cin>>xx;
            input[i].push_back(xx);
        }
    }
    dp.clear();
    dp.resize(k+5,vector<int> (m+5,0));
    f(m,k, input);
    
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


