#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<bitset>
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

string f(string s){
    string ans= "";
    for(int i= 0; i<31; i++){
        if(s[i] == '0') ans +='1';
        else ans+= '0';
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    
    unordered_map<string,int> s2;
    int count = 0;
    for(int i = 0; i<n; i++){
        string str = bitset<31>(input[i]).to_string();
        string str2 = f(str);
        if(s2[str2] > 0  and s2[str] == 0) {
            //cout<<'y'<<endl;
            //cout<<s2[str2]<<" ";
            s2[str2]--;
            continue;
        }
        //cout<<endl;
        count++;
        s2[str]++;
        // debug(str);
        // debug(str2);
    }
    cout<<count<<endl;

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