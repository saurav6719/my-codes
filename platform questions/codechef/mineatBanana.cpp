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

bool poss(int mid, queue<int>qu, int sum, int hour){
    debug(mid);
    int time = 0;
    while(!qu.empty()){
        debug(qu.front());
        if(qu.front() > mid){
            qu.push(qu.front() - mid); 
        }
        qu.pop();
        time++;
    }

    return (time <= hour);
}
void solve(){
    int n;
    int h;
    cin>>n;
    cin>>h;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    } 
    queue<int> qu;
    sort(input.begin(), input.end(), greater<int> ());
    int sum = 0;
    for(int i = 0; i<n;i++){
        qu.push(input[i]);
        sum+= input[i];
    }
    int lo = 0;
    int hi = input[0];
    int result = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(poss(mid,qu, sum,h)){
            result = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout<<result<<endl;
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