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
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    string str;
    cin>>str;

    vector<int> xor0(n+1);
    vector<int> xor1(n+1);

    xor0[0] = xor1[0] = 0;
    
    for(int i = 0; i<n; i++){
        if(str[i] == '0'){
            xor0[i+1] = xor0[i] ^ input[i];
            xor1[i+1] = xor1[i];
        }
        else{
            xor1[i+1] = xor1[i] ^ input[i];
            xor0[i+1] = xor0[i];
        }
    }

    int ans0 = xor0[n];
    int ans1 = xor1[n];

    int q;
    cin>>q;;
    while(q--){
        int type;
        cin>>type;

        if(type == 1){
            int l,r;
            cin>>l>>r;

            ans0 = ans0 ^ xor0[r] ^ xor0[l-1] ^ xor1[r] ^ xor1[l-1];
            ans1 = ans1 ^ xor1[r] ^ xor1[l-1] ^ xor0[r] ^ xor0[l-1];
        }


        else{
            int xx;
            cin>>xx;
            if(xx == 1){
                cout<<ans1<<" ";
            }
            else cout<<ans0<<" ";


        }
    }

    cout<<endl;

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

