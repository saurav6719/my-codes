#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
int cnt=0;
vector<string> outpt;
unordered_set<string> st;
void f(string input,string output){
    //base case
    if(input.size() == 0){
        cnt++;
        outpt.push_back(output);
        return;
    }
    for(int i = 0;i<input.size();i++){  
        char ch = input[i];
        string left = input.substr(0,i);
        string right = input.substr(i+1);
        string ros = left + right;
        string s = ros + "," + output + ch;
        if(st.count(s)) continue;
        st.insert(s);
        f(ros,output+ch);
    }
}
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    outpt.clear();
    f(str,"");
    cout<<cnt<<endl;
    
    for(int i=0;i<outpt.size();i++){
        cout<<outpt[i]<<endl;
    }
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