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
    int k;
    cin>>k;
    vector<int> per(n+1);
    for(int i = 1; i<=n; i++){
        per[i] = i;
    }
    //print(per);
    vector<int> per_copy = per;

    if(k & 1){
        cout<<"No"<<endl;
        return;
    }
    int maxi; 
    if(n & 1){
        int xx = n-1;
        xx /= 2;
        maxi = xx * (xx+1);
        maxi *= 2;
    }
    else{
        int xx = n;
        xx/=2;
        maxi = xx * xx;
        maxi *= 2;
    }

    //debug(maxi);

    if(k > maxi){
        cout<<"No"<<endl;
        return;
    }

    int i = 1;
    int j = n;

    while(k>0){
        int curr = 2 * (abs(j-i));
        if(k>= curr){
            per_copy[i] = per[j];
            per_copy[j] = per[i];
            i++;
            j--;
            k-= curr;
        }
        else{
            i++;
        }
    }
    cout<<"Yes"<<endl;
    for(int a = 1; a<=n; a++){
        cout<<per_copy[a]<<" ";
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

