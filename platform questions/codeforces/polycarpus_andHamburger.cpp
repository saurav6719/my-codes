#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
// #include<bits/stdc++.h>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));  
#define mx(a,b,c) max(a,max(b,c));
#include<unordered_map>
using namespace std;
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;
    cin>>s;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    int r;
    cin >> r;
    int cnt = 0;
    unordered_map<char, int> mp;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    } 
    if(nb >= mp['B'] && ns >= mp['S'] && nc >= mp['C']){
        int first = nb/mp['B'];
        int second = ns/ mp['S'];
        int third = nc / mp['C']; 
        if(mp['B'] == 0) first = INT_MAX;
        if(mp['S'] == 0) second = INT_MAX;
        if(mp['C'] == 0) third = INT_MAX;
        int plus = mn (first,second,third);
        cnt += plus;
        nb -= plus * mp['B'];
        nc -= plus * mp['C'];
        ns -= plus * mp['S'];
    }
    while(r>=0 and (nb != mp['B'] or  ns != mp['S'] or nc != mp['C'])){
        if(nb<mp['B']){
        // required = mp['B'] - nb;
            r-= pb * (mp['B'] - nb);
            nb = mp['B'];
        }

        if(ns < mp['S']){
            r-= ps * (mp['S'] - ns);
            ns = mp['S'];
        }
        if(nc < mp['C']){
            r-= pc * (mp['C'] - nc);
            nc = mp['C'];
        }
        if(r>=0) {
            cnt++;
        }
        if(nb == mp['B'] and ns == mp['S'] and nc == mp['C']) break;
        nb -= mp['B'];
        nc -= mp['C'];
        ns -= mp['S'];
    } 
    if(r<=0){
        cout<<cnt<<endl;
        return;
    }
    int costOfOne = 0;
    costOfOne += pb * mp['B'];
    costOfOne += ps * mp['S'];
    costOfOne += pc * mp['C'];
    cnt += r/costOfOne;
    cout << cnt << endl;
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