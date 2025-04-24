#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr----  " << #x << " " << x << endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while (0)
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
                } while (0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while (0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while (0)
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
#define mn(a, b, c) min(a, min(b, c))
#define mx(a, b, c) max(a, max(b, c))
#define pp pair<int, int>
const int p = 31;      // Base for hash function

using namespace std;

void computeHashAndPowers(const string &s, vector<long long> &prefix_hash, vector<long long> &p_pow) {
    int n = s.size();
    prefix_hash.resize(n + 1, 0);
    p_pow.resize(n, 1);

    // Compute powers of p up to n
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % mod;
    }

    // Compute prefix hash values
    for (int i = 0; i < n; ++i) {
        prefix_hash[i + 1] = (prefix_hash[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }
}

long long getHash(int l, int r, const vector<long long> &prefix_hash, const vector<long long> &p_pow) {
    long long hash_value = (prefix_hash[r + 1] - prefix_hash[l] + mod) % mod;
    hash_value = (hash_value * p_pow[p_pow.size() - r - 1]) % mod; // Align hash
    return hash_value;
}

vector<int> findPrefixSuffixMatches(const string &s) {
    int n = s.size();
    vector<long long> prefix_hash, p_pow;
    computeHashAndPowers(s, prefix_hash, p_pow);

    vector<int> matches;

    for (int len = 1; len < n; ++len) {
        long long prefix_h = getHash(0, len - 1, prefix_hash, p_pow);
        long long suffix_h = getHash(n - len, n - 1, prefix_hash, p_pow);

        if (prefix_h == suffix_h) {
            matches.push_back(len);
        }
    }

    return matches;
}

bool find(int mid, string &str) {
    int n = str.size();
    if (mid >= n - 1) return false; // Pattern too long to be inside

    vector<long long> prefix_hash, p_pow;
    computeHashAndPowers(str, prefix_hash, p_pow);
    long long pattern_hash = getHash(0, mid - 1, prefix_hash, p_pow);

    for (int i = 1; i <= n - mid - 1; ++i) {
        long long substring_hash = getHash(i, i + mid - 1, prefix_hash, p_pow);
        if (substring_hash == pattern_hash) {
            return true;
        }
    }

    return false;
}

void solve() {
    string str;
    cin >> str;
    vector<int> result = findPrefixSuffixMatches(str);
    sort(result.begin(), result.end());

    for(auto ele : result){
        cout<<ele<<" ";
    }
    

    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
