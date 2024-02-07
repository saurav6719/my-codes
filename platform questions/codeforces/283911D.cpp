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
    int result = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(input[mid] >= x){
            result = mid;
            hi = mid -1;
        }
        else lo = mid + 1;
    }
    return result;
}

int binarySearch2(vector<int> &input,int x){
    int lo = 0; 
    int hi = input.size() - 1;
    int result = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(input[mid] <= x){
            result = mid;
            lo = mid +1;
        }
        else hi = mid -1;
    }
    return result;

}




void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i];   // 1 3 4 10 10
    }

    sort(input.begin(), input.end());
    int k;
    cin>>k;
    while(k--){
        int l;
        cin>>l;
        int r;
        cin>>r;
        int a = lower_bound(input.begin(), input.end(), l) - input.begin();
        // cout<<a<<endl;
        if(a==n) {
            cout<<"0"<<endl;
            return;
        }
        debug(a);
        int b = upper_bound(input.begin(),input.end(), r) - input.begin();
        debug(b);
        cout<<b-a<<" ";
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