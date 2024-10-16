// Author : Shivam Kapoor
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << x << endl
#define print(v) cerr << #v << " = [ "; for (auto &el : v) cerr << el << " "; cerr << "]\n";
#define print2d(v) cerr << #v << ":\n"; for (auto &row : v) { cerr << "[ "; for (auto &el : row) cerr << el << " "; cerr << "]\n"; }
#define printmap(m) cerr << #m << ":\n"; for (auto &[key, value] : m) cerr << key << " -> " << value << "\n";
#define printpp(v) cerr << #v << " = [ "; for (auto &[first, second] : v) cerr << "(" << first << ", " << second << ") "; cerr << "]\n";

#define vll vector<ll>
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)

inline vector<ll> bitRep(ll num) {
    vector<ll> bits(64, 0);
    for (int i = 0; i < 64; i++) {
        bits[63 - i] = (num >> i) & 1;
    }
    return bits;
}

inline ll mysqrt(ll n) {
    ll i = max(0LL, (ll)sqrt(n) - 2);
    while (i * i <= n) ++i;
    return i - 1;
}

const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;

void solve() {
    ll n, k, d; cin >> n >> k >> d;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;
    vector<ll> v(k);
    for(ll i = 0;i < k; i++) cin >> v[i];

    v.insert(v.begin(), 0);
    vector<ll> b = a;
    b.insert(b.begin(), 0);

    ll ans = 0;
    for(ll i = 1; i <= n+1; i++){
        if(b[i] == i) ans++;
    }
    for(ll i = 1; i <= v[0]; i++){
        b[i]++;
    }
    for(ll i = 2; i <= min(d, k); i++){
        ll score = 0;
        ll end = v[i];
        ll days_left = d - i + 1;
        if(days_left > 0) score += (days_left) / 2;
        for(ll j = 1; j <= end; j++) b[j]++;
         
        ans = max(ans, score);    
    }

    cout << ans << endl;
}


int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
