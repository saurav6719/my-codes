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
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
vector<int> rabin_karp(string const& s, string const& t) {
    const int p1 = 31, p2 = 53;
    const int m1 = 1e9 + 7, m2 = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p1_pow(max(S, T)), p2_pow(max(S, T));
    p1_pow[0] = p2_pow[0] = 1;
    for (int i = 1; i < (int)p1_pow.size(); i++) {
        p1_pow[i] = (p1_pow[i-1] * p1) % m1;
        p2_pow[i] = (p2_pow[i-1] * p2) % m2;
    }

    vector<pair<long long, long long>> h(T + 1, {0, 0});
    for (int i = 0; i < T; i++) {
        h[i+1].first = (h[i].first + (t[i] - 'a' + 1) * p1_pow[i]) % m1;
        h[i+1].second = (h[i].second + (t[i] - 'a' + 1) * p2_pow[i]) % m2;
    }

    pair<long long, long long> h_s = {0, 0};
    for (int i = 0; i < S; i++) {
        h_s.first = (h_s.first + (s[i] - 'a' + 1) * p1_pow[i]) % m1;
        h_s.second = (h_s.second + (s[i] - 'a' + 1) * p2_pow[i]) % m2;
    }

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        pair<long long, long long> cur_h = {
            (h[i+S].first + m1 - h[i].first) % m1,
            (h[i+S].second + m2 - h[i].second) % m2
        };
        pair<long long, long long> h_s_shifted = {
            (h_s.first * p1_pow[i]) % m1,
            (h_s.second * p2_pow[i]) % m2
        };

        if (cur_h == h_s_shifted) {
            occurrences.push_back(i);
        }
    }
    return occurrences;
}

void solve(){
    string text;
    cin>>text;
    string pattern;
    cin>>pattern;

    vector<int> result = rabin_karp(pattern, text);
    cout<<result.size()<<endl;

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

