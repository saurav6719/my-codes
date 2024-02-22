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
    int n,k;
    cin>>n>>k;
    vector<int> integers(n);
    for(int i = 0; i<n; i++){
        cin>>integers[i];
    }
    vector<int> friends(k);
    for(int i = 0; i<k; i++){
        cin>>friends[i];
    } 
    vector<int> give(k);
    sort(integers.begin(), integers.end());
    sort(friends.begin(), friends.end());
    int j = n-1;
    int happiness = 0;
    for(int i = 0; i<k; i++){
        friends[i]--;
        give[i] = integers[j];
        j--;
    }
 
    for(int i = 0; i<k; i++){
        if(friends[i] == 0) happiness += 2*give[i];
        else{
            j-=friends[i];
            happiness+= give[i];
            happiness += integers[j+1];
        }
    }
 
    cout<<happiness<<endl;

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