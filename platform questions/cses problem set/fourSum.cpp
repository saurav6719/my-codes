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
    int x;
    cin>>n;
    cin>>x;
    vector<pair<int,int> >input(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i].first;
        input[i].second = i+1;
    }
    sort(input.begin(), input.end());

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int l = j+1; 
            int r = n-1;
            int target = x - input[i].first - input[j].first;

            while(l!=r and l<n and r>=0){
                if((input[l].first + input[r].first) == target){
                    std:: cout<<input[i].second<<" "<<input[j].second<<" " <<input[l].second<<" "<<input[r].second;
                    return;
                }
                else if((input[l].first + input[r].first) < target){
                    l++;
                }
                else r--;
            }
        }
    }
    std ::cout<<"IMPOSSIBLE";
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

