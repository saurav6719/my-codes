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
    int m;
    cin>>n>>m;
    vector<vector<char> > input(n, vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
        }
    }

    if(input[0][0] == input[n-1][m-1]){
        cout<<"YES"<<endl;
        return;
    }

    bool one = false;
    bool two = false;

    char chlow = input[n-1][m-1];

    for(int i = n-2; i>=0; i-- ){
        if(input[i][m-1] != chlow){
            one = true;
            break;
        }
    }

    for(int i = m-2; i>=0; i--){
        if(input[n-1][i] != chlow){
            two = true;
            break;
        }
    }

    if(one==true and two==true){
        cout<<"YES"<<endl;
        return;
    }

    bool three = false;
    bool four = false;

    char chup = input[0][0];

    for(int i = 1; i<n; i++ ){
        if(input[i][0] != chup){
            three = true;
            break;
        }
    }

    for(int i = 1; i<m; i++){
        if(input[0][i] != chup){
            four = true;
            break;
        }
    }

    if(three==true and four==true){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;


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

