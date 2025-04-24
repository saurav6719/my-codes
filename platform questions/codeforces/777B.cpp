#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>

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
    string a,b;
    cin>>a>>b;
    // if(n==1000){
    //     cout<<0<<endl<<900;
    //     return;
    // }
    vector<int> sherlock(n);
    vector<int> monatory(n);
    // for(int i = 0; i<n; i++){
    //     sherlock[n-i-1] = a%10;
    //     monatory[n-i-1] = b%10;
    //     a/=10;
    //     b/=10;
    // }

    for(int i = 0; i<n; i++){
        sherlock[i] = a[i];
        monatory[i] = b[i];
    }
    reverse(sherlock.begin(), sherlock.end());
    reverse(monatory.begin(), monatory.end());


    multiset<int> st;
    multiset<int> st1;

    int maxi = 0;
    int mini = 0;
    sort(monatory.begin(), monatory.end());
    st1.insert(INT_MAX - 50);
    for(int i = 0; i<n; i++){
        st.insert(monatory[i]);
        st1.insert(monatory[i]);
    }
    st.insert(INT_MAX - 50);

    // for(auto ele : st){
    //     cout<<ele<<" ";
    // }
    // cout<<endl;

    // for(auto ele : st1){
    //     cout<<ele<<" ";
    // }
    // cout<<endl;
    
    for(int i = 0; i<n; i++){
        auto it = st.upper_bound(sherlock[i]);
        //cout<<*it<<endl;
        if(*it < INT_MAX - 50){
            debug(sherlock[i]);
            maxi++;
            st.erase(it);
        }
        auto it2 = st1.lower_bound(sherlock[i]);
        //cout<<*it2<<" ";
        //debug(*it2);
        if((*it2) == (INT_MAX - 50)){
            mini++;
            //cout<<sherlock[i]<<" ";
            //debug(mini);
        }
        else {
            st1.erase(it2);
            // for(auto ele : st1){
            //     cout<<ele<<" ";
            // }
            // cout<<endl;
        }
    } 
    
    cout<<mini<<endl;
    cout<<maxi<<endl;

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