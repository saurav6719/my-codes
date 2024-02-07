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
    int m;
    cin>>m;
    int k;
    cin>>k;
    vector<int> first(n);
    unordered_set<int> st1;
    unordered_set<int> st2;
    for(int i= 0; i<n; i++){
        int ele;
        cin>>ele;
        first[i] = ele;
        st1.insert(ele);
    }
    vector<int> second(m);
    for(int i= 0; i<m; i++){
        int ele;
        cin>>ele;
        second[i] = ele;
        st2.insert(ele);
    }
    int cn1 = k/2;
    int cn2 = k/2;
    unordered_set<int> st3;
    for(int i = 1; i<=k; i++){
        if(st1.count(i) > 0 and st2.count(i) == 0 and cn1>0){
            debug(i);
            cn1--;
            debug(cn1);
            st3.insert(i);
        }
        if(st1.count(i) == 0 and st2.count(i) > 0 and cn2 > 0){
            debug(i);
            cn2--;
            debug(cn2);
            st3.insert(i);
        }
    }
    for(int i = 1; i<=k; i++){
        if(st3.count(i) == 0){
            if(st1.count(i) > 0 and st2.count(i) > 0){
                if(cn1>cn2) {
                    cn1--;
                    st3.insert(i);
                }
                else {
                    cn2--;
                    st3.insert(i);
                }
            }
        }
    }
    for(int i = 1; i<=k; i++){
        if(st3.count(i) == 0){
            cout<<"NO"<<endl;
                return;
        }
    }
    cout<<"YES"<<endl;
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