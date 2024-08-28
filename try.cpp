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

 
void solve() {
    string str;
    cin >> str;
    int n = str.size();
    vector<int> result = findPrefixSuffixMatches(str);
    sort(result.begin(), result.end());

    if(result.size() == 0){
        cout<<"NO"<<endl;
        return;
    }
    if(result.back() == n) result.pop_back();
    
    int len = result.back();
    debug(len);

    if(len + len < n) {
        cout<<"NO"<<endl;
        return;
    }

    string ans = str.substr(0, len);
    print(ans);

    vector<int> xx = rabin_karp(ans, str);
    print(xx);

    if(xx.size() > 1){
        // xx.erase(xx.begin());
        // xx.pop_back();
        if(xx[0] + len == xx[1]){
            cout<<"NO"<<endl;return;
        }
    }
    else{
        cout<<"NO"<<endl;return;
    }

    if(xx.size() > 0){
        cout<<"YES"<<endl;
        int occ = xx[0];
        debug(occ);
        if(occ + len == n){
            cout<<"NO"<<endl;
            return;
        }
        for(int j = occ; j< occ+len ; j++){
                cout<<str[j];
        }
    }


    else    cout<<"NO"<<endl;
 
    
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