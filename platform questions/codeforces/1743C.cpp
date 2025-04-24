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
    string s;
    cin>>s;
    vector<int> a(n);
    for(int i= 0; i<n; i++){
        cin>>a[i];
    }
    vector<int> zero;
    for(int i = 0; i<n; i++){
        if(s[i] == '0') zero.push_back(i);
    }

    int sum = 0;

    if(zero.size() > 0){
        int firstzero = zero[0];
        if(firstzero != 0){
            for(int i = 0; i<firstzero; i++){
                sum += a[i];
            }
        }
    }
    for(int i = 1; i<zero.size(); i++){
        int lastzero = zero[i-1];
        int zeroidx = zero[i];
        int ones = zeroidx - lastzero - 1;
        sort(a.begin() + lastzero, a.begin() + zeroidx, greater<int> ());
        int j = lastzero;
        while(ones--){
            sum += a[j];
            j++;
        }
    }
    if(zero[zero.size() - 1] != n-1){
        int lastzero = zero[zero.size() - 1];
        int ones = (n- lastzero - 1);
        sort(a.begin() + lastzero, a.end(), greater<int> ());
        int j = lastzero;
        while(ones--){
            sum += a[j];
            j++;
        }
    }
    cout<<sum<<endl; 
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