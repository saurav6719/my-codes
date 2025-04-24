#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
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
    string input;
    cin>>input;
    stack<char> st;
    int ans = 0;
    int res = INT_MIN;
    int res2 = INT_MIN;
    int final = 0;
    for(int i = 0; i<input.size(); i++){
        if(st.empty() and input[i] == ')') {
            ans = 0;
            
            cout<<"nwo"<< " "<<i<<endl;
            debug(ans);
        }
        if(input[i] == ')' and !st.empty() and st.top() == '('){
            ans+=2;
            res = max(res, ans);
            st.pop();
        }
        if(input[i] == '('){
            st.push(input[i]);
        }
    }
    if(st.empty()) res = max(res, ans);
    ans = 0;
    while(!st.empty()) st.pop();
    for(int i = 0; i<input.size(); i++){
        if(st.empty() and input[i] == ')') {
            ans = 0;
            
            cout<<"nwo"<< " "<<i<<endl;
            debug(ans);
        }
        if(input[i] == ')' and !st.empty() and st.top() == '('){
            ans+=2;
            res2 = max(res2, ans);
            if(res2 == res and ans == res) final++;
            debug(final);
            debug(ans);
            debug(i);
            st.pop();
        }
        if(input[i] == '('){
            st.push(input[i]);
        }
    }
    if(st.empty()) {
        if(res2 == res and ans == res) final++;
    }
    if(res<= INT_MIN+50){
        cout<<0<<" "<<1;
        return;
    }

    cout<<res<<" "<<final;
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