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

void solveee(){
    int n;
    cin>>n;
    int k;
    cin>>k;string str;
    cin>>str;

    cout<<str;
}
void solve(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    string str;
    cin>>str;

    for(int i = 0; i<n; i++){
        if(str[i] != '?'){
            if((i+k)<n and str[i+k] == str[i]) continue;
            else if((i+k)<n and str[i+k] == '?'){
                str[i+k] = str[i];
            }
            else if(i+k<n){
                //cout<<"YE"<<endl;
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    for(int i = n-1; i>=0; i--){
        if(str[i] != '?'){
            if((i-k)>=0 and str[i-k] == str[i]) continue;
            else if((i-k)>=0 and str[i-k] == '?'){
                str[i-k] = str[i];
            }
            else if(i-k>=0){
                //cout<<"HJAg"<<endl;
                cout<<"NO"<<endl;
                return;
            }
        }
    }

   //print(str);

    int i = 0;
    int j = k;
    int cnt0= 0;
    int cnt1= 0;
    int cntq = 0;

    for(int i = 0; i<k; i++){
        if(str[i] == '0') cnt0++;
        else if(str[i] == '1') cnt1++;
        else cntq++;
    }

    // debug(cnt0);
    // debug(cnt1);
    // debug(cntq);
    
    if(abs(cnt1 - cnt0) > cntq){
        cout<<"NO"<<endl;
        return;
    }

    while(j<n){
        if( str[j] != '?' and str[i] != '?' and str[j] != str[i]){
            cout<<"NO"<<endl;
            return;
        }
        i++;j++;
    }

    cout<<"YES"<<endl;
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
    for(int i = 1; i<=t; i++){
        solve();
    }
return 0;
}

