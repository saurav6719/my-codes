

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
    int k;
    cin>>n>>k;
    vector<int> input(k);

    for(int i = 0; i<k; i++){
        cin>>input[i];
    }

    sort(input.begin(), input.end());

    int cntmore = 0;
    int cntone = 0;
    int ans = 0;


    for(int i = 0; i<k-1; i++){
        if(input[i] == 1) {
            cntone++;
            continue;
        }
        cntmore += input[i];
        ans += input[i] -1;
    }

    ans += (cntmore + cntone);
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

