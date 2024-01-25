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
    int n,k;
    cin>>n>>k;
    vector<int> input(k);
    for(int i = 0 ; i<k;i++){
        cin>>input[i];
    }

    sort(input.begin(),input.end());
    int cat = 0;
    int count = 0;

    int i = k-1;
    while(i>=0){
        int dist = n-input[i];
        if(cat < input[i]){
            count++;
            cat += (n-input[i]);
        }
        
        else break;
        i--;

    }
    cout<<count<<endl;
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