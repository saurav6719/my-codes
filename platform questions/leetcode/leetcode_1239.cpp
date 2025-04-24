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
//#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
//link -> https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
void solve(){
    class Solution {
public:
int result = INT_MIN;
void f(vector<string> &arr , string output, int n,int i, unordered_set<char> st, bool flag ){
    if(i>=n) {
        result = max(int(result) , int(output.size()));
        return; 
    }

    f(arr , output , n, i+1,st,false);
    
    for(int j = 0; j<arr[i].size(); j++){
        if(st.count(arr[i][j])) {
            flag = true;
            break;
        }
        st.insert(arr[i][j]);
    }
    if(!flag) {
        f(arr,output+arr[i],n,i+1,st,false);
        if(output.size() > 0) output.pop_back();
    }

    
}
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        unordered_set<char> st;
        f(arr,"",n,0,st,false);
        return result;
    }
};
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