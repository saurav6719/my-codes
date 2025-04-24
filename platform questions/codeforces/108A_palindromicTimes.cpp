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
void solve(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int num = 0;
  num = num + (s[0] - '0')*1000;
  num = num + (s[1] - '0')*100;
  num = num + (s[3] - '0')*10;
  num = num + (s[4] - '0')*1;
  if(num >= 0000 && num < 110) cout << "01:10" << endl;
  else if(num >= 110 && num < 220) cout << "02:20" << endl;
  else if(num >= 220 && num < 330) cout << "03:30" << endl;
  else if(num >= 330 && num < 440) cout << "04:40" << endl;
  else if(num >= 440 && num < 550) cout << "05:50" << endl;
  else if(num >= 550 && num < 1000) cout << "10:01" << endl;
  else if(num >= 1000 && num < 1111) cout << "11:11" << endl;
  else if(num >= 1111 && num < 1221) cout << "12:21" << endl;
  else if(num >= 1221 && num < 1331) cout << "13:31" << endl;
  else if(num >= 1331 && num < 1441) cout << "14:41" << endl;
  else if(num >= 1441 && num < 1551) cout << "15:51" << endl;
  else if(num >= 1551 && num < 2002) cout << "20:02" << endl;
  else if(num >= 2002 && num < 2112) cout << "21:12" << endl;
  else if(num >= 2112 && num < 2222) cout << "22:22" << endl;
  else if(num >= 2222 && num < 2332) cout << "23:32" << endl;
  else if(num >= 2332 && num <= 2359) cout << "00:00" << endl;

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