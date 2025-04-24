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
bool cmp(pair<int,int> &a , pair<int, int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int> > input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first>>input[i].second;
    }

    sort(input.begin(), input.end(), cmp);

    // for(auto ele: input){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }

    int one = INT_MIN;
    int two = INT_MIN;

    for(int i = 0; i<n; i++){
        int start = input[i].first;
        int end = input[i].second;
        if(start > one){
            one = end;
            continue;
        }

        if(start > two){
            two = end;
            continue;
        }

        cout<<"NO"<<endl;
        return;

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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

