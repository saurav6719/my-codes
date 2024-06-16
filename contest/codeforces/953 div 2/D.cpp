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
    int c;
    cin>>c;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    input[0] += c;

    int maxi = INT_MIN;
    int reqidx = -1;
    for(int i = 0; i<n; i++){
        if(input[i] > maxi){
            maxi = input[i];
            reqidx = i;
        }
    }

    //debug(reqidx);
    //cout<<reqidx<<endl;


    vector<int> ans(n);

    vector<int> prf(n);
    prf[0] = input[0];
    for(int i = 1; i<n; i++){
        prf[i] = prf[i-1] + input[i];
    }

    //print(prf);

    for(int i = 0; i<n; i++){
        if(i== reqidx){
            ans[i] = 0;
            continue;
        }

        else if(i<reqidx){
            int curr = input[i] + ((i==0) ? 0 : prf[i-1]);
            //debug(curr);
            if(curr >= input[reqidx]){
                ans[i] = i;
            }
            else ans[i] = i+1;
        }

        else{
            ans[i] = i;
        }
    }

    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
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

