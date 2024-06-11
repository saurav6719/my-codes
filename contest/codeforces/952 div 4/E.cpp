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
 
// std::vector<int> primeFactorization(int n) {
//     std::vector<int> factors;
 
//     // Divide by 2 until n is odd
//     while (n % 2 == 0) {
//         factors.push_back(2);
//         n /= 2;
//     }
 
//     // Divide by odd numbers from 3 upwards
//     for (int i = 3; i * i <= n; i += 2) {
//         while (n % i == 0) {
//             factors.push_back(i);
//             n /= i;
//         }
//     }
 
//     // If n is a prime number greater than 2
//     if (n > 2) {
//         factors.push_back(n);
//     }
 
//     return factors;
// }
 
std::vector<int> findFactors(int n) {
    std::vector<int> factors;
 
    // Iterate from 1 to sqrt(n)
    for (int i = 1; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
 
    return factors;
}
 
void findTriplets(const std::vector<int>& factors, int n, std::vector<std::vector<int>> & triplets, int xx, int yy, int zz) {
    int size = factors.size();
    std::vector<int> triplet(3);

    // Iterate through all combinations of triplets
    for (int i = 0; i < size; i++) {
        //debug(factors[i]);
        if(factors[i] > xx and factors[i] > yy and factors[i] > zz) break;
        for (int j = i; j < size; j++) {
            if(factors[j] > xx and factors[j] > yy and factors[j] > zz) break;
            for (int k = j; k < size; k++) {
                if(factors[k] > xx and factors[k] > yy and factors[k] > zz) break;
                if (factors[i] * factors[j] * factors[k] == n) {
                    triplet[0] = factors[i];
                    triplet[1] = factors[j];
                    triplet[2] = factors[k];
                    std::sort(triplet.begin(), triplet.end());
                    triplets.push_back(triplet);
                }
            }
        }
    }
}
 
 
void solve(){
    int x;
    int y;
    int z;
    cin>>x>>y>>z;
    int v;
    cin>>v;
 
    vector<int> ss;
    ss.push_back(x);
    ss.push_back(y);
    ss.push_back(z);
    sort(ss.begin(), ss.end());
 
    x = ss[0];
    y = ss[1];
    z = ss[2];
 
    // vector<int> pf = primeFactorization(v);
    // pf.push_back(1);
 
    // sort(pf.begin(), pf.end());
    // //print(pf);
 
    // vector<int> pfmf(pf.size());
    // vector<int> pfml(pf.size());
 
    // pfmf[0] = pf[0];
    // pfml[pf.size() - 1] = pf[pf.size() - 1];
 
    // for(int i = 1; i<pf.size(); i++){
    //     pfmf[i] = pfmf[i-1] * pf[i];
    // }
 
    // for(int i = pf.size()-2; i>=0; i--){
    //     pfml[i] = pfml[i+1] * pf[i];
    // }
 
    //print(pfmf);
    // print(pfml);
    int ans = 0;
 
    vector<int> fac = findFactors(v);

    sort(fac.begin(), fac.end());
 
    //print(fac);
    vector<vector<int> > triplets;
    findTriplets(fac , v , triplets,x,y,z);
 
    //cout<<triplets.size();
 
    // for(auto ele : triplets){
    //     print(ele);
    // }
 
    // for(auto ele : triplets){
    //     if(ele[0] == 1700){
    //         cout<<ele[1]<<" "<<ele[2]<<endl;
    //     }
    //}
 
    for(int i = 0; i<triplets. size(); i++){
            
                int a = triplets[i][0];
                int b = triplets[i][1];
                int c = triplets[i][2];
 
                // debug(a);
                // debug(b);
                // debug(c);
 
                
 
                
                int xx = x - a;
                int yy = y - b;
                int zz = z - c;
                if(xx>=0 and yy>=0 and zz>=0){
                    ans = max(ans , (xx+1)*(yy+1)*(zz+1));
                }
 
                // int xxx = x - a;
                // int yyy = y - c;
                // int zzz = z - b;
                // if(xxx>=0 and yyy>=0 and zzz>=0){
                //     ans = max(ans , (xxx+1)*(yyy+1)*(zzz+1));
                // }
                
 
                // int xxxx = x - b;
                // int yyyy = y - a;
                // int zzzz = z - c;
                // if(xxxx>=0 and yyyy>=0 and zzzz>=0){
                //     ans = max(ans , (xxxx+1)*(yyyy+1)*(zzzz+1));
                // }
 
                // int xxxxx = x - b;
                // int yyyyy = y - c;
                // int zzzzz = z - a;
                // if(xxxxx>=0 and yyyyy>=0 and zzzzz>=0){
                //     ans = max(ans , (xxxxx+1)*(yyyyy+1)*(zzzzz+1));
                // }
 
                // int xxxxxx = x - c;
                // int yyyyyy = y - a;
                // int zzzzzz = z - b;
                // if(xxxxxx>=0 and yyyyyy>=0 and zzzzzz>=0){
                //     ans = max(ans , (xxxxxx+1)*(yyyyyy+1)*(zzzzzz+1));
                // }
 
                // int xxxxxxx = x - c;
                // int yyyyyyy = y - b;
                // int zzzzzzz = z - a;
 
                // // debug(xxxxxxx);
                // // debug(yyyyyyy);
                // // debug(zzzzzzz);
                // if(xxxxxxx>=0 and yyyyyyy>=0 and zzzzzzz>=0){
                //     ans = max(ans , (xxxxxxx+1)*(yyyyyyy+1)*(zzzzzzz+1));
                // }                
            
        
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}