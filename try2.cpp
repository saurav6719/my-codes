
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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
} while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int inversioncnt(vector<int> &v2, vector<int> &v1){
    map<int,int> mp;
    for(int i = 0; i<v1.size(); i++){
        mp[v1[i]] = i;
    }
    int cnt = 0;
    for(int i = 0; i<v2.size(); i++){
        int now = i;
        int then = mp[v2[i]];
        if(now < then) cnt++;
        else if(now > then) cnt--;
    }
    return cnt;
}
void solve(){
    int n;
    cin>>n;
    vector<int> v(n, 0);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    vector<int> even;
    vector<int> odd;
    for(int i = 0; i<n; i++){
        if(i%2 == 0) even.push_back(v[i]);
        else odd.push_back(v[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    vector<int> ans;
    int evencurr = 0;
    int oddcurr = 0;
    for(int i = 0; i<n; i++){
        if(i%2 == 0){
            ans.push_back(even[evencurr]);
            evencurr++;
        }
        else{
            ans.push_back(odd[oddcurr]);
            oddcurr++;
        }
    }

    vector<int> v2;
    for(int i = n-1; i>=0; i-=2){
        v2.push_back(ans[i]);
    }
    vector<int> v1;
    for(int i = n-1; i>=0; i-=2){
        v1.push_back(v[i]);
    }
    print(v1);
    print(v2);

    vector<int> v3;
    vector<int> v4;
    for(int i = n-2; i>=0; i-=2){
        v3.push_back(ans[i]);
    }
    for(int i = n-2; i>=0; i-=2){
        v4.push_back(v[i]);
    }
    print(v3);
    print(v4);
    int d = inversioncnt(v3,v4);
    int c = inversioncnt(v1,v2);
    debug(c);
    debug(d);
    c = abs(c);
    d = abs(d);

    if(c % 2 != d%2 ){
        swap(ans[ans.size() -3] , ans[ans.size() - 1]);
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
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

