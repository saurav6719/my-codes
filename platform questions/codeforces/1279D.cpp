#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr----  " << #x << " " << x << endl
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
#define mod 998244353
#define mn(a, b, c) min(a, min(b, c))
#define mx(a, b, c) max(a, max(b, c))
#define pp pair<int, int>
using namespace std;

class Fraction {
public:
    int num;   // Numerator
    int denom; // Denominator

    Fraction(int numerator = 0, int denominator = 1) : num(numerator), denom(denominator) {
        normalize();
    }

    void normalize() {
        if (denom < 0) { // Handle negative denominator
            num = -num;
            denom = -denom;
        }
        int gcd = std::gcd(num, denom);
        num /= gcd;
        denom /= gcd;
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
    }

    Fraction add(const Fraction& other) const {
        int newNum = ((num * other.denom) % mod + (other.num * denom) % mod) % mod;
        int newDenom = (denom * other.denom) % mod;
        return Fraction(newNum, newDenom);
    }

    Fraction multiply(const Fraction& other) const {
        int newNum = (num * other.num) % mod;
        int newDenom = (denom * other.denom) % mod;
        return Fraction(newNum, newDenom);
    }
};

// Function to perform modular exponentiation
int modExp(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to find the modular inverse using modular exponentiation
int modInverse(int b) {
    return modExp(b, mod - 2);
}

// Function to perform modular division
int modDivision(int a, int b) {
    a = (a % mod + mod) % mod; // Ensure a is positive
    int inv = modInverse(b);
    return (inv * a) % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> input(n, vector<int>());
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        for (int j = 0; j < ele; j++) {
            int a;
            cin >> a;
            input[i].push_back(a);
            mp[a]++;
        }
    }

    Fraction ans(0, 1);

    for (int i = 0; i < n; i++) {
        int no_of_elements = input[i].size();
        Fraction f1(1, no_of_elements);
        Fraction f2(0, 1);
        for (int j = 0; j < no_of_elements; j++) {
            int occurrence = mp[input[i][j]];
            Fraction f3(occurrence, n);
            f2 = f2.add(f3);
        }
        f2 = f2.multiply(f1);
        ans = ans.add(f2);
        debug(f2.num);
        debug(f2.denom);
    }
    debug(ans.num);
    debug(ans.denom);

    Fraction f(1, n);
    ans = ans.multiply(f);

    int x = ans.num;
    int y = ans.denom;

    int y_inv = modInverse(y);
    cout << modDivision(x, y) << endl;
}

/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
