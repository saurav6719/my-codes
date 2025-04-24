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
    int total = n*(n+1)/2;
    if(total&1){
        cout<<"NO";
        return;
    }
    int half = total/2;
    int i = n;
    unordered_set<int> first;
    unordered_set<int> second;
    int sum = 0;
    while(true){
        sum+=i;
        if(sum<=half){
            first.insert(i);
        }
        else{
            sum-=i;
            if((half - sum ) != 0) first.insert(half - sum);
            break;
        }
        i--;
    }

    for(int i = 1; i<=n;i++){
        if(first.count(i) == 0) second.insert(i);
    }

    cout<<"YES"<<endl;
    cout<<first.size()<<endl;
    for(auto ele: first){
        cout<<ele<<" ";
    }
    cout<<endl;
    cout<<second.size()<<endl;
    for(auto ele: second){
        cout<<ele<<" ";
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