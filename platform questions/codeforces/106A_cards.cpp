#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;

int ranking(char ch){
    if(ch == 'T') return 10;
    if(ch == 'J') return 11;
    if(ch == 'Q') return 12;
    if(ch == 'K') return 13;
    if(ch == 'A') return 14;
    return 0;
}
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    char ch;
    cin>>ch;
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    bool ans = false;
    if(s1[1] == ch and s2[1] != ch) {
        ans = true;
        cout<<"YES";
        return;
    }
    if(s1[1] != ch and s2[1] == ch){
        ans = false;
        cout<<"NO";
        return;
    }
    if(s1[1] == s2[1]){ //same suit check rank
        if((s1[0] >= 65 and s1[0] <= 90) and (s2[0] >= 65 and s2[0] <= 90) ){ // both are letters
            char ch1 = s1[0];
            char ch2 = s2[0];
            int first = ranking(ch1);
            int second = ranking(ch2);
            if(first > second) ans = true;
        }
        else if((s1[0] >= 65 and s1[0] <= 90) and (s2[0] < 65 and s2[0] > 90) ){
            ans = true;
        }
        else{
            if(s1[0] > s2[0]) ans = true;
        }
    }
    if(ans) cout<<"YES";
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