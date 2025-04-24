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
#define check() cout<<"check ---1000"<<endl;
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

    if(n<k){
        cout<<"NO"<<endl;
        return;
    }
    if(n==k){
        cout<<"YES"<<endl;
        cout<<"2"<<endl;
        cout<<"1"<<" "<<"1"<<endl;
        return;
    }
    vector<int> ans;
    if(n %  k == 0){
        ans.push_back(n/k);
        ans.push_back(1);
        cout<<"YES"<<endl;
        cout<<"2"<<endl;
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    int cost = n / k;
    debug(cost);
    int div = n/cost;
    debug(div);

    if(div == k){
        
        ans.push_back(cost);
        ans.push_back(cost+1);
        cout<<"YES"<<endl;
        cout<<"2"<<endl;
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(div > k){
        check();
        int kminus1 = k-1;
        int n_copy = n;
        n_copy --;

        int quo = n_copy / (k-1); // 14 / 3 = 4
        n_copy = quo * (k-1);
        debug(n_copy);
        debug(quo);

        if(n_copy < k-1){
            cout<<"NO"<<endl;
            return;
        }
        
        else{
            ans.push_back(n_copy / (k -1));
            if(n/ (n_copy / (k-1)) >= k){
                cout<<"NO"<<endl;
                return;
            }
            ans.push_back(n-n_copy);
            cout<<"YES"<<endl;
            cout<<"2"<<endl;
            for(int i = 0; i<ans.size(); i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
            return;
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

