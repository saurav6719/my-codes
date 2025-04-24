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
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> input(n);

    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    sort(input.begin(), input.end(), greater<int> ());

    for(int i = 1; i<n; i++){
        input[i] += input[i-1];
    }

    


    while(q--){
        int xj;
        cin>>xj;
        int result = -1;
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(input[mid] >= xj){
                result = mid;
                hi = mid -1;
            }
            else lo = mid+1;
        }
        if(result == -1) cout<<-1<<endl;
        else cout<<result + 1<<endl;
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