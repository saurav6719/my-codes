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
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    string s;
    cin>>n;
    cin>>s;
    int start = n+5;
    int cnt = 0; 
    int lftcnt =0;
    int rgtcnt = 0;
    int end;
    int last;
    for(int i = 0; i<n;i++){
        if(s[i] == '.') continue;
        start = min(start, i+1);
        cnt ++;
        if(s[i] == 'L') lftcnt++;
        if(s[i] == 'R') rgtcnt++;
    }
    last = start + cnt;
    end = last - lftcnt;
    if(lftcnt > 0) end -= 1;
    cout<<start<<" "<<end;

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