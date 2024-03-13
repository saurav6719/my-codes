
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
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int cnt = 0;
    map<int,int> mp;
    int j = 0;
    for(int i = 0 ;i<n; i++){
        while(j<n and(mp.size() < k or mp.count(input[j]) > 0)){
            mp[input[j]]++;
            j++;
        }
        cnt += j - i;
        debug(cnt);
        mp[input[i]]--;
        debug(mp[input[i]]);
        if(mp[input[i]] == 0){
            mp.erase(input[i]);
        }
    }

    cout<<cnt;
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

