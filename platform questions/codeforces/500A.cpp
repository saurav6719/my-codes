#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_set>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){//ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    int t ;
    cin>>t;
    vector<int> input(n-1);
    for(int i = 0; i<n-1; i++){
        cin>>input[i];
    }
    unordered_set<int> st;
    st.insert(1);
    int i = 0;
    while(i<n-1){
        int next = (i+1) + input[i];
        st.insert(next);
        i+= input[i];
    }
    if(st.count(t)) cout<<"YES";
    else cout<<"NO";
}
int32_t main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}