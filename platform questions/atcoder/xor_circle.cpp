
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

    map<int,int> mp;

    for(int i = 0; i<n; i++){
        cin>>input[i];
        mp[input[i]]++;
    }
    if(mp.size() ==1 and input[0] == 0){
        cout<<"YES";
        return ;
    }

    vector<pair<int,int> > v(mp.begin(), mp.end());

    if(mp.size() == 2 and v[0].first == 0){
        int x = v[0].second;
        int y = v[1].second;
        if(3*x == n or 3*y == n){
            cout<<"YES";
            return;
        }
    } 

    if(n%3 != 0  or mp.size() != 3) {
        debug(mp.size());
        cout<<"NO";
        return;
    }
    int first = -1;
    int second = -1;
    int third = -1;

    

    if(v[0].second != v[1].second or v[1].second != v[2].second){
        cout<<"NO";
        return;
    }

    for(auto ele : mp){
        if(first == -1) {
            first = ele.first;
            continue;
        }
        if(second == -1){
            second = ele.first;
            continue;
        }
        third = ele.first;
    }
    debug(first);
    debug(second);
    debug(third);

    if((first ^ second ^ third)== 0){
        cout<<"YES";
    }
    else cout<<"NO";
    
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

