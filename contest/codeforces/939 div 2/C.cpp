
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
    vector<int> rowsum(n+1,0);
    vector<int> colsum(n+1,0);
    int persum = n*(n+1)/2;
    //debug(persum);
    vector<int> permutation;
    for(int i = n ;i>=1; i--){
        permutation.push_back(i);
    }
    vector<vector<int> > ans(n+1, vector<int> (n+1));
    int s= 0;
    int m = 0;
    vector<vector<int> >output;
    int n_copy = n;

    while(n_copy >= 1){
        //debug(n_copy);
        for(int i = n; i>=n - n_copy + 1; i--){
            output.push_back({1,i});
            for(int j = 1; j<=n; j++){
                ans[i][j] = permutation[j-1];
            }
        }

        n_copy = n_copy/2 ;

        if(n_copy < 1) break;
        for(int i = n; i>=n - n_copy + 1; i--){
            output.push_back({2,i});
            for(int j = 1; j<=n; j++){
                ans[j][i] = permutation[j-1];
            }
        }
        n_copy = n_copy/2 ;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            s+= ans[i][j];
        }
    }

    m = output.size();

    cout<<s<<" "<<m<<endl;
    for(int i = 0; i<output.size(); i++){
        for(int j = 0; j<output[i].size(); j++){
            cout<<output[i][j]<<" ";
        }
        for(int k = 0 ;k<n; k++){
            cout<<permutation[k]<<" ";
        }
        cout<<endl;
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



