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
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    priority_queue<int, vector<int> > pq;

    for(int i = 0; i<n; i++){
        cin>>input[i];
        if(i>=1){
            pq.push(input[i]);
        }
    }
    

    int cnt = 0;
    while(input[0] <= pq.top()){
        int curr = pq.top();
        //debug(curr);
        pq.pop();
        input[0]++;
        cnt++;
        curr--;
        pq.push(curr);
    }
    cout<<cnt;

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