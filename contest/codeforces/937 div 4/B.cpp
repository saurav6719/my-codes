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
    int n;
    cin>>n;
    vector<char> line1;
    vector<char> line2;
    vector<char> line3;
    vector<char> line4;
    int cnt = 0;
    for(int i = 0; i<2*n; i+=2){
        if(!cnt){
          line1.push_back('#');
          line1.push_back('#');
          cnt = !cnt;
        }
        else{
          line1.push_back('.');
          line1.push_back('.');
          cnt = !cnt;
        }
    }
    //print(line1);
    line2 = line1;
    int cnt2 = 0;
    for(int i = 0; i<2*n; i+=2){
        if(!cnt2){
          line3.push_back('.');
          line3.push_back('.');
          cnt2 = !cnt2;   
        }
        else{
          line3.push_back('#');
          line3.push_back('#');
          cnt2 = !cnt2;
        }
    }
    //print(line3);
    int cnt3 = 0;
    for(int i = 0; i<2*n; i+=2){
      if(!cnt3){
        for(int j = 0; j<line1.size(); j++){
          cout<<line1[j];
        }
        cout<<endl;
        for(int j = 0; j<line1.size(); j++){
          cout<<line1[j];
        }
        cout<<endl;
        cnt3 = !cnt3;
      }
      else{
        for(int j = 0; j<line1.size(); j++){
          cout<<line3[j];
        }
        cout<<endl;
        for(int j = 0; j<line1.size(); j++){
          cout<<line3[j];
        }
        cout<<endl;
        cnt3 = !cnt3;
      }
    }

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

