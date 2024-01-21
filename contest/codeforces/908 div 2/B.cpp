#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<< #x <<" " <<x<<endl 
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
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    if(input.size() < 4) {
        cout<<"-1"<<endl;
        return;
    }
    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++){
        mp[input[i]] ++;
    }
    int cnt = 0;
    for(auto ele:mp){
        if(ele.second >= 2) cnt++;
    }
    if(cnt < 2){
        cout<<"-1"<<endl;
        return;
    }
    int a = -1, b = -1;
    bool flag = false;

    for(auto  ele : mp){
        if(a!= -1 and b!= -1) break;
        if(ele.second >= 2 and !flag){
            a = ele.first;
            flag = true;
        }
        else if(ele.second >= 2 and flag){
            b= ele.first;
        }
    }

    int c,d;
    vector<int> output(n,1);
    int first = 0;
    int second = 0;
    for(int i = 0; i<n; i++){
        if(input[i] == a and first == 0) {
            output[i] = 1;
            first++;
        }
        else if(input[i] == a and first == 1){
            output[i] = 2;
            c = i;
            first ++;
        }
        else if(input[i] == b and second == 0) {
            output[i] = 1;
            second++;
        }
        else if(input[i] == b and second == 1){
            output[i] = 3;
            d = i;
            second ++;
        }
    }
    if(input[c] == input[d]) {
        cout<<"-1"<<endl;
        return;
    }

    for(int i = 0; i<n; i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
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