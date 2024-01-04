#include<iostream>
#include<string>
using namespace std;

void solve(){
  string s1, s2, s3, s4;
  cin >> s1 >> s2 >> s3 >> s4;
 
  int len1 = s1.length()-2;
  int len2 = s2.length()-2;
  int len3 = s3.length()-2;
  int len4 = s4.length()-2;
  int cnt1 = 0;
  if((len1 >= 2*len2 && len1 >= 2*len3 && len1 >= 2*len4) || (len1 <= len2/2 && len1 <= len3/2 && len1 <= len4/2)){
    cnt1++;
  }
  int cnt2 = 0;
  if((len2 >= 2*len1 && len2 >= 2*len3 && len2 >= 2*len4) || (len2 <= len1/2 && len2 <= len3/2 && len2 <= len4/2)){
    cnt2++;
  }
  int cnt3 = 0;
  if((len3 >= 2*len2 && len3 >= 2*len4 && len3 >= 2*len1) || (len3 <= len2/2 && len3 <= len4/2 && len3 <= len1/2)){
    cnt3++;
  }
  int cnt4 = 0;
  if((len4 >= 2*len1 && len4 >= 2*len2 && len4 >= 2*len3) || (len4 <= len1/2 && len4 <= len2/2 && len4 <= len3/2)){
    cnt4++;
  }
 
  if(cnt1 + cnt2 + cnt3 + cnt4 == 1){
    if(cnt1) cout << "A" << endl;
    if(cnt2) cout << "B" << endl;
    if(cnt3) cout << "C" << endl;
    if(cnt4) cout << "D" << endl;
  }
  else{
    cout << "C" << endl;
  }
}
int main(){
    int tc;
    //cin >> tc;
    tc = 1;
    while(tc--){
        solve();
    }
  return 0;
    return 0;
}