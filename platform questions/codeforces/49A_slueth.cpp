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
bool isletter(char ch){
    if(ch >= 65 and ch <=90) return true;
    if(ch >=97 and ch <= 122) return true;
    return false;
}
bool isVowel(char ch){
    if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'y' || ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U' or ch == 'Y') return true;
    return false;
}
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin,s);
    bool ans = false;

    for (int i = s.size() - 1; i >= 0; i--) {
        char ch = s[i];
        
        int asc = ch;
        if(!isletter(ch)) continue;
        if (isletter(ch)) {
            if (isVowel(ch)) {
                ans = true;
            }
            else ans = false;
            break;
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