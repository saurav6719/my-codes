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
bool intersect(int mini, int maxi, int l, int r){
    if(l<= mini and r>=mini ) return true;
    if(l>=mini and r<=maxi ) return true;
    if(l<=maxi and r>= maxi) return true;
    if(l<=mini and r>= maxi) return true;
    return false;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<pair<int,int> , int> > input(n);

    for(int i = 0; i<n; i++){
        cin>>input[i].first.first>>input[i].first.second;
        input[i].second = i;
    }

    sort(input.begin(), input.end());

    int g1min = input[0].first.first;
    int g1max = input[0].first.second;

    vector<int> ans(n, -1);

    ans[input[0].second] = 1;

    for(int i = 1; i<n; i++){
        int a = input[i].first.first;
        int b = input[i].first.second;
        if(intersect(g1min, g1max, a,b)){
            g1min = min(g1min, a);
            g1max = max(g1max, b);
            ans[input[i].second] = 1;
        }
        else ans[input[i].second] = 2;
    }
    print(ans);

    bool check = false;

    for(int i = 0; i<n; i++){
        if(ans[i] == 2){
            check = true;
            break;
        }
    }

    if(!check){
        cout<<-1<<endl;
        return;
    }

    for(auto ele : ans){
        cout<<ele<<" ";
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

