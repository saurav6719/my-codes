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

bool cmp(pair<int,int> &a, pair<int,int> & b){
    if(a.first == b.first) return (a.second > b.second);
    return (a.first > b.first);
}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    for(int i = 0; i<n; i++){
        int rem = input[i] % k;
        if(rem == 0) {
            input[i] = 0;
            continue;
        }
        input[i] = k-rem;
    }
    print(input);
    map<int,int> freq;
    for(int i=0 ;i<n; i++){
        freq[input[i]]++;
    }
    vector<pair<int,int> > pairss;
    for(auto ele : freq){
        pairss.push_back({ele.second, ele.first});
    }
    sort(pairss.begin(), pairss.end(), cmp);
    bool check = false;
    int ans = 0;
    debug(pairss[0].first);
    debug(pairss[0].second);
    int start = 0;
    for(int i = 0;i<pairss.size() ;i++){
        if(pairss[start].second == 0) start++;
        else break;
    }
    ans += pairss[start].second;
    for(int i = 0; i<n; i++){
        if(input[i] != 0){
            check = true;
            break;
        }
    }
    ans += (k*(pairss[start].first - 1));
    ans++;
    if(!check){
        cout<<0<<endl;
        return;
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

