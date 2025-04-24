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

const int MAXN = 1e6 + 5;
const int ALPHABET_SIZE = 26;

void solve() {
    int n;
    cin >> n;

    int q;
    cin >> q;
    vector<char> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    vector<char> input2(n);
    for (int i = 0; i < n; i++) {
        cin >> input2[i];
    }

    // Precompute prefix frequencies
    vector<vector<int>> prefixFreq1(n, vector<int>(ALPHABET_SIZE, 0));
    vector<vector<int>> prefixFreq2(n, vector<int>(ALPHABET_SIZE, 0));

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            prefixFreq1[i] = prefixFreq1[i-1];
            prefixFreq2[i] = prefixFreq2[i-1];
        }
        prefixFreq1[i][input[i] - 'a']++;
        prefixFreq2[i][input2[i] - 'a']++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        vector<int> freq1(ALPHABET_SIZE, 0);
        vector<int> freq2(ALPHABET_SIZE, 0);

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            freq1[i] = prefixFreq1[r][i] - (l > 0 ? prefixFreq1[l-1][i] : 0);
            freq2[i] = prefixFreq2[r][i] - (l > 0 ? prefixFreq2[l-1][i] : 0);
        }

        int cnt = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (freq2[i] > freq1[i]) {
                cnt += freq2[i] - freq1[i];
            }
        }
        cout << cnt << endl;
    }
}

/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
