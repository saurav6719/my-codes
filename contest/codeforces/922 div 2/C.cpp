#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
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

int findMostSignificantDifferingBit(int a, int b) {
    int xorResult = a ^ b;
    int differingBit = 0;

    // Find the position of the most significant differing bit
    while (xorResult) {
        xorResult >>= 1;
        differingBit++;
    }

    return differingBit;
}

void solve(){
    int a,b,r;
    cin>>a>>b>>r;
    if(a<b) swap(a,b);
    int x = 0ll;
    int first = findMostSignificantDifferingBit(a,b) - 1;
    debug(first);
    bool ok = false;
    for(int i = first - 1; i>=0; i--){
        debug(i);
        debug((a&(1ll<<i)));
        debug((b&(1ll<<i)));
        if((a & (1ll<<i)) >= 1 and (b&(1ll<<i)) == 0){
            debug((x|(1ll<<i)));
            if((x | (1ll<<i)) <= r){
                debug(r);
                //cout<<"YES"<<endl;
                x |= (1ll<<i);
            }
            debug(x);
        }
    }
    if(x==0) {
        if(r==0) cout<<abs(a-b)<<endl;
        else {
            cout<<min((abs(a^b)), (abs((a^1) - (b^1))))<<endl;
        }
    }
    else {
        cout<<(abs((a^x) - (b^x)))<<endl;
    }
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