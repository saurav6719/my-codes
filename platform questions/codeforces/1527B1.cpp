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
bool isPalindrome(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return str == reversed;
}
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    if(n%2==0){
        cout<<"BOB"<<endl;
        return;
    }
    if(n&1){
        if(str[n/2] == '0'){
            //debug(n/2);
            //cout<<"ghvh"<<endl;
            str[n/2] = '1';
        }
        else {
            cout<<"BOB"<<endl; 
            return;
        }
    }
   
    //cout<<str[1]<<endl;
    if(isPalindrome(str)){
       //cout<<"fagsf"<<endl;
        int alicecnt = 1;
        int bobcnt = 0;
        for(int i = 0; i<n; i++){
            if(str[i] == '0') bobcnt++;
        }
        if(bobcnt < alicecnt){
            cout<<"BOB"<<endl;
            return;
        }
        else if(alicecnt == bobcnt){
            cout<<"DRAW"<<endl;
            return;
        }
        else {
            cout<<"ALICE"<<endl;
            return;
        }
    }
    else{
        cout<<"BOB"<<endl;
        return;
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

