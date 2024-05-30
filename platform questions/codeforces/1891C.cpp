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
    sort(input.begin(), input.end());
    int i = 0; 
    int j = n-1;
    int surplus = 0;
    int ans = 0;
    while(i<=j){
        while(i<j and surplus < input[j]){
            surplus += input[i];
            if(surplus > input[j]){
                int xx = surplus - input[j];
                ans += input[i] - xx;
                input[i] = surplus - input[j];
                surplus = input[j];
                continue;
            }
            ans += input[i];
            i++;
        }
        debug(i);

        if(i >= j){
            int diff = input[j] - surplus;
            debug(input[j]);
            debug(surplus);
            if(input[j] == 1){
                ans++;
                break;
            }
            if(diff & 1){
                ans += (diff + 1)/2;
            }
            else ans += (diff / 2);
            ans++;
            break;
        }

        else{
            ans ++;
            surplus -= input[j];
            //debug(surplus);
            j--;
        }
        debug(j);
        debug(ans);
    }


    cout<<ans<<endl;

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

