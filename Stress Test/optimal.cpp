/**
 *    author: Saurav
 *    created: 2025.07.13 09:11:26
 *    We stop at Candidate Master in 2025
 **/

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
#define printset(s)
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
char processStr(string s, long long k) {
        int n = s.size();
        int sz = 0;
        vector<int> v;
        for(auto ele : s){
            if(ele == '#') sz*=2;
            else if (ele == '*') {
                if(sz > 0) sz--;
            }
            else if(ele == '%') {

            }
            else sz++;

            v.push_back(sz);
        }
        v.push_back(k);
        print(v);

        if(sz < k) return '.';
        int curr = k;
        for(int i = n-1; i>=0; i--){
            if(v[i] == 0 or i == 0) {
                debug(curr);
                int cnt =0 ;
                for(int j = i; j<n; j++){
                    if(s[j] >='a' and s[j] <= 'z'){
                        cnt++;
                        if(cnt == curr){
                            return s[j];
                        }
                    }
                }
            }
            int pichlahai = v[i-1];
            int aagechahiye = curr;
            if(s[i] == '#'){
                if(curr == pichlahai){
                    curr = pichlahai;
                }
                else curr = curr % pichlahai;
            }
            else if(s[i] == '*'){

            }
            else if(s[i] == '%'){
                curr = pichlahai - aagechahiye + 1;
            }
            debug(pichlahai);
            debug(aagechahiye); 
            debug(curr);
        }
        return '.';
}
void solve(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    char ans = processStr(s, k);
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

