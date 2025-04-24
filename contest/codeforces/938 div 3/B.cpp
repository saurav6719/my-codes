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
    int c;
    int d;
    cin>>n>>c>>d;
    vector<int> input(n*n);
    for(int i = 0; i<n*n; i++){
        cin>>input[i];
    }

    sort(input.begin(), input.end());
    //print(input);
    int a11 = input[0];
    vector<vector<int> > output(n, vector<int> (n));
    output[0][0] = a11;
    for(int i = 0; i<n; i++){
        //debug(i);
        if(i>0) output[i][0] = output[i-1][0] + c;
        //if(i>0) debug(output[i-1][0]);
        for(int j = 1; j<n; j++){
            output[i][j] = output[i][j-1] + d;
        }
    }

    vector<int> comp;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            comp.push_back(output[i][j]);
        }
    }

    sort(comp.begin(), comp.end());

    for(int i = 0; i<n*n; i++){
        if(comp[i] != input[i]){
            cout<<"NO"<<endl;
            return;
        }
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
    while(t--){
        solve();
    }
return 0;
}

