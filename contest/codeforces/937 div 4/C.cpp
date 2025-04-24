/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    string str;
    cin>>str;
    int ff = str[0] - '0';
    int ss = str[1] - '0';
    char tt = str[3];
    char ft = str[4];
    int hour = ff*10+ ss;
    //debug(hour);
    if(hour == 12){
      cout<<str<<" "<<"PM"<<endl;
      return;
    }
    if(hour == 0){
      cout<<"12:"<<tt<<ft<<" "<<"AM"<<endl;
      return;
    }
    bool am = false;
    if(hour <12){
      am = true;
    }
    if(am){
      cout<<str<<" "<<"AM"<<endl;
      return;
    }

    if(am == false){
      hour -= 12;
      int sss = hour%10;
      hour/=10;
      int fff = hour%10;
      char ffff = fff + '0';
      char ssss = sss + '0';
      cout<<ffff<<ssss<<":"<<tt<<ft<<" "<<"PM"<<endl;
      return;

    }
    string ans ;



}
/* logic ends */

signed main(){
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

