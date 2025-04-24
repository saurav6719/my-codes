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
    string str;
    cin>>str;
    vector<int> quantity(3);
    vector<int> prices(3);
    for(int i = 0; i<3;i++){
        cin>>quantity[i];
    }
    for(int i = 0; i<3;i++){
        cin>>prices[i];
    }
    int r;
    cin>>r;

    int a=0;
    int b=0;
    int c=0;

    for(int i = 0; i<str.size();i++){
        if(str[i] == 'B') a++;
        if(str[i] == 'S') b++;
        if(str[i] == 'C') c++;
    }
    int result = 0;
    int lo = 0;
    int hi = r+200;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        int r1 = ((a*mid) - quantity[0]);
        if(r1<0) r1 = 0;
        r1 *= prices[0];

        int r2 = ((b*mid) - quantity[1]);
        if(r2<0) r2 = 0;
        r2 *= prices[1];

        int r3 = ((c*mid) - quantity[2]);
        if(r3<0) r3 = 0;
        r3 *= prices[2];

        if(r1+r2+r3 <= r){
            result = mid;
            lo = mid+1;

        }
        else{
            hi = mid-1;
        }
    }

    cout<<result;

}
int32_t main(){
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