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
void solve(){//ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    char c;
    cin>>c;
    string input;
    cin>>input;
    if(c == 'g'){
        cout<<"0"<<endl;
        return;
    }
    
    int lastOccurenceOfC = 0;
    bool flag = false;
    int firstOccurenceOfg = 0;
    int lastOccurenceOfg = 0;
    int ans = 0;

    int i = 0;
    int j = 0;

    int a = 0;
    while(a<n){
        if(input[a] == 'g'){
            firstOccurenceOfg = a;
            break;
        }
        a++;
    }
    while(i<n){
        
        if(input[i] == c){
            lastOccurenceOfC = max(lastOccurenceOfC , i);
            j= i+1;
            while(j<n) {
                if(input[j] != 'g') j++;
                else break;
            }
            if(j==n) {
                //cout<<"j is terminateded "<<i<<j<<endl;
                ans = max(ans , j-i+ firstOccurenceOfg);
                break;
            }
            lastOccurenceOfg = j;
            ans = max(ans, j-i);
            i = j+1;
        }
        else i++;
    }
    cout<<ans<<endl;
}
int32_t main(){
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}