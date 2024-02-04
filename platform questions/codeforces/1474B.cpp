#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;


void solve(){
    vector<bool> sieve(100000, 1); // 1 represents prime
    sieve[0] = 0;
    sieve[1] = 0;

    for(int i = 2; i * i<=100000; i++){
        if(sieve[i] == 0) continue;
        for(int j = i * i; j<=100000; j+=i){    // complexity O(n log(log n)) for n queries 
            sieve[j] = 0;
        }
    }
    int d;
    cin>>d;
    int ans = 1;
    int count = 0;
    int first = 1+d;
    for(int i = first; i<=100000 and count<2; ){
        if(sieve[i] == true){
            ans *= i;
            count++;
            i+=d;
        }
        else i++;
    }

    cout<<ans<<endl;
    
}
int32_t main(){
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