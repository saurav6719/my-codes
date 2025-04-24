// // /*
// //   ------------------------------------------
// //  |                                        |
// //  |      Code Crafted by Saurav     |
// //  |                                        |
// //   ------------------------------------------
// //     \        ,     ,        /
// //       \      |     |      /
// //          \   \___/   /
// //            \  -----  /
// //              \_____/
  
// //   Happy coding! 
// // */

// // /* includes and all */

// // #include<bits/stdc++.h>
// // #ifndef ONLINE_JUDGE
// // #define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
// // #define print(v) do { \
// //                     cout << "vect--" << #v << " = [ "; \
// //                     for (int i = 0; i < v.size(); i++) { \
// //                         cout << v[i] << " "; \
// //                     } \
// //                     cout << " ]" << endl; \
// //                 } while(0)
// // #else
// // #define debug(x)
// // #define print(v)
// // #endif
// // #define endl "\n"
// // #define int long long int
// // #define mod 1000000007
// // #define mn(a,b,c) min(a,min(b,c))
// // #define mx(a,b,c) max(a,max(b,c))
// // using namespace std;

// // /* write core logic here */
// // vector<int> dp;
// // int f(int n){
// //     //function will count no of steps to reduce n to 1
// //     //base case 
// //     if(dp[n] != -1) return dp[n];
// //     if(n==1)  return  dp[n] = 0;
// //     if(n==2) return dp[n] = 1;
// //     if(n==3) return dp[n] = 1;
// //     int ans =  min(f(n-1), min(((n%2==0)?f(n/2) : INT_MAX), ((n%3==0) ? f(n/3) : INT_MAX)))+1;
// //     return dp[n] = ans;
// // }
// // void solve(){
// //     int n;
// //     cin>>n;
// //     dp.clear();
// //     dp.resize(n+5,-1);
// //     cout<<f(n);
// // }
// // /* logic ends */

// // signed main(){
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
// //     #ifndef ONLINE_JUDGE
// //         freopen("Error.txt" , "w" , stderr);
// //     #endif
// //     int t;
// //     //cin>>t;
// //     t = 1;
// //     while(t--){
// //         solve();
// //     }
// // return 0;
// // }



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
// vector<int> dp;
// int f(int n){
//     //function will count no of steps to reduce n to 1
//     //base case 
//     dp[0] = INT_MAX;
//     dp[1] = 0;
//     dp[2] = 1;
//     dp[3] = 1;

//     for(int i = 4; i<=n; i++){
//         dp[i] = min(dp[i-1], min(((i%2==0)?dp[i/2] : INT_MAX), ((i%3==0) ? dp[i/3] : INT_MAX)))+1;
//         debug(i);
//         debug(dp[i]);
//     }
//     return dp[n];
// }
// void solve(){
//     int n;
//     cin>>n;
//     dp.clear();
//     dp.resize(n+5,INT_MAX);
//     cout<<f(n);
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

