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

bool isOneLessPowerOfTwo(int num) {
    // If a number is one less than a power of two,
    // it will have only one bit set and that bit will
    // be in a position other than the least significant bit.
    // For example: 7 (111), 31 (11111), 63 (111111), 127 (1111111)
    return (num & (num + 1)) == 0 && num != 0;
}

unsigned int nearestSmallerPowerOfTwo(unsigned int num) {
    if (num <= 1) return 0; // Special case for 0 and 1

    // Find the most significant bit (MSB) position
    unsigned int msbPos = 0;
    unsigned int temp = num;
    while (temp > 1) {
        temp >>= 1;
        msbPos++;
    }

    // Set all bits after the MSB position to 0
    return 1 << msbPos;
}



void solve(){
    int n,k;
    cin>>n>>k;
    if(n==1){
        cout<<k<<endl;
        return;
    }
    vector<int> ans;
    if(isOneLessPowerOfTwo(k)){
        ans.push_back(k);
        for(int i = 0 ; i<n-1; i++){
            ans.push_back(0);
        }

        for(auto ele: ans){
            cout<<ele<<" ";
        }
        cout<<endl;
        return;
    }

    int nearest = nearestSmallerPowerOfTwo(k);
    ans.push_back(nearest - 1);
    
    ans.push_back(k - (nearest - 1));
    for(int i = 0; i<n-2; i++){
        ans.push_back(0);
    }

    for(auto ele: ans){
            cout<<ele<<" ";
    }
    cout<<endl;


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

