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
    int n,k,m;
    cin>>n>>k>>m;
    string str;
    cin>>str;
    unordered_set<char> st;
    for(int i = 0; i<k; i++){
        st.insert(char(i+97));
    }
    unordered_set<char> st1 = st;
    int i = 0;
    int j = 0; 
    vector<string> parts;
    string last ="";
    while(j<m){
        if(st.size() == 0){
            parts.push_back(str.substr(i,j-i));
            i=j;
            st = st1;
            last.clear();
        }
        if(st.count(str[j])!=0){
            last += str[j];;
            st.erase(str[j]);
        }
        j++;
    }
    if(st.size() == 0){
            parts.push_back(str.substr(i,j-i));
            i=j;
            st = st1;
            last.clear();
    }
    if(parts.size() >=n){
        cout<<"YES"<<endl;
        return;
    }
    string ans = "";
    for(int i = 0; i<last.size();i++){
        if(st1.count(last[i]) != 0){
            st1.erase(last[i]);
        }
    }
    char ch ;
    for(auto ele : st1){
        ch = ele;
        break;
    }
    for(int i = 0; i<parts.size(); i++){
        ans += parts[i][parts[i].size() -1];
    }

    int o = ans.size();

    int remain = n-o;
    for(int a = 0; a<remain; a++){
        ans += ch;
    }

    cout<<"NO"<<endl;
    cout<<ans<<endl;
    return;
    


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