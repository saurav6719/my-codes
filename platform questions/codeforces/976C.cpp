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
bool cmp(pair<pair<int, int>, int>  &a, pair<pair<int, int>, int> &b){
    if(a.first.first == b.first.first) return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<pair<int,int> , int > >input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first.first>>input[i].first.second;
        input[i].second = i;
    }

    sort(input.begin(), input.end(), cmp);

    // for(auto ele : input){
    //     cout<<ele.first.first<<" "<<ele.first.second<<" "<<ele.second<<endl;
    // }

    int curr = input[0].first.second;
    int a = input[0].second;
    for(int i = 1; i<n; i++){
        if(input[i].first.second <= curr){
            cout<<input[i].second+1<<" "<<a+1<<endl;
            return;
        }
        if(input[i].first.second > curr){
            curr = input[i].first.second;
            a = input[i].second;
        }
    }

    cout<<-1<<" "<<-1;


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

