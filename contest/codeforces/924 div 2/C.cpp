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
void factors(vector<int> & v, int n){
    for(int i = 1; i*i <=n ; i++){
        if(n % i ==0) {
            if(i*i == n) v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
}
void solve(){
    int n;
    int x;
    cin>>n>>x;
    int ans = 0;
    vector<int> v;
    int a = n-x;
    int b = n+x-2;
    factors(v,a);
    unordered_set<int> st;
    for(auto ele : v){
        if(ele % 2 == 0){
            int k = (ele+2)/ 2;
            if(k>=x) {
                st.insert(k);
            }
        }
    }
    vector<int> v1;
    factors(v1,b);
    for(auto ele : v1){
        if(ele % 2 == 0){
            int k = (ele+2)/ 2;
            if(k>=x) {
                st.insert(k);
            }
        }
    }
    
    cout<<st.size()<<endl;
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