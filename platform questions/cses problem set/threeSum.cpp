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

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

/* write core logic here */
void solve(){
    int n;
    int x;
    cin>>n;
    cin>>x;
    vector<pair<int,int> >input(n);
    vector<int> index(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i].first;
        input[i].second = i+1;
    }
    

    sort(input.begin(), input.end(), comparePairs);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            
            if(i==j) continue;
            debug(i);
            debug(j);
            int sum = input[i].first + input[j].first;
            debug(sum);
            int target = x - sum;
            if(target < 0 ) break;
            int idx = lower_bound(input.begin(), input.end(), make_pair(target,0), comparePairs) - input.begin();
            debug(idx);
            if(input[idx].first == target and input[idx].second != input[i].second and input[idx].second != input[j].second){
                
                cout<<input[i].second<<" "<<input[j].second<<" "<<input[idx].second<<endl;
                return;
            }
            if(input[idx+1].first == target and input[idx+1].second != input[i].second  and input[idx+1].second != input[j].second){
                
                cout<<input[i].second<<" "<<input[j].second<<" "<<input[idx+1].second<<endl;
                return; 
            }
            if(input[idx+2].first == target and input[idx+2].second != input[i].second and input[idx+2].second != input[j].second){
                debug(input[idx+2].second);
                cout<<input[i].second<<" "<<input[j].second<<" "<<input[idx+2].second<<endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    

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

