#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define ll long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    string str1,str2;
    cin>>str1>>str2;
    int i = 0; 
    int j = 0;
    vector<int> v1 ;
    vector<int> v2 ;
    bool flag = true;
    if(str1.size() != str2.size()) flag = false;
    int n = str1.size();
    for(int i = 0; i<n; i++){
        if(str1[i] != str2[i]){
            v1.push_back(str1[i]);
            v1.push_back(str2[i]);
        }
    }
    if(v1.size() != 2 or v2.size() != 2) flag = false;
    if(v1[0] != v2[1] and v1[1] != v2[0]) flag = false;

    if(flag) cout<<"YES";
    else cout<<"NO";
}
int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
    solve();
    }
return 0;
}