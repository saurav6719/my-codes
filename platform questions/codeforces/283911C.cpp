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

int binarySearch(vector<int> &input,int x){
    int lo = 0; 
    int hi = input.size() - 1;
    int result = input.size();
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        
        if(input[mid] >= x){
            result = mid;
            hi = mid -1;
        }
        else lo = mid +1;
    }
    return result + 1;

}

void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    while(k--){
        int x;
        cin>>x;
        cout<<binarySearch(input,x)<<endl;
    }

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