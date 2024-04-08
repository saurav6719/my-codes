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

#define int long long
#define INF LLONG_MAX


void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> input(n);
    int t_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        t_sum += input[i];
    }
    int  s_copy = t_sum- s;
    if(s_copy==0){
        cout<<0<<endl;
        return;
    }
    set<int> st1;
    set<int> st2;
    vector<int> prfl(n);
    vector<int> prfr(n);
    prfl[0] = input[0];
    st1.insert(input[0]);
    prfr[n-1] = input[n-1];
    st2.insert(input[n-1]);
    for(int i = 1; i<n; i++){
        prfl[i] = prfl[i-1]+input[i];
        st1.insert(prfl[i]);
    }
    print(prfl);
    for(int i = n-2; i>=0; i--){
        prfr[i] = prfr[i+1] + input[i];
        st2.insert(prfr[i]);
    }
    if(!st1.count(s) and !st2.count(s)) {
        cout<<-1<<endl;
        return;
    }
    reverse(prfr.begin(), prfr.end());
    print(prfr);

    int ans = min(lower_bound(prfl.begin(), prfl.end(), s_copy) - prfl.begin() + 1, lower_bound(prfr.begin(), prfr.end(), s_copy) - prfr.begin() + 1);
    debug(ans);
    
    for(int i  =0; i<n; i++){
        
        int ele = prfl[i];
        if(ele >= s_copy) break;
        int req = s_copy - ele;
        int ss = lower_bound(prfr.begin(), prfr.end(), req) - prfr.begin();
        debug(ss);
        debug(i+1);
        ans = min(ans , i+1+ss+1);
    }

    for(int i  =0; i<n; i++){
        
        int ele = prfr[i];
        if(ele >= s_copy) break;
        int req = s_copy - ele;
        int ss = lower_bound(prfl.begin(), prfl.end(), req) - prfl.begin();
        debug(ss);
        debug(i+1);
        ans = min(ans , i+1+ss+1);
    }
    
    cout<<ans<<endl;

    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
