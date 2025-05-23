#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")

using namespace std;

const int N = 2e5 + 5;

struct Node {
    int l, r;
    vector<int> sorted;
    vector<int> llink, rlink;
};

vector<Node> seg(4 * N);
vector<int> x;

void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    if (l == r) {
        seg[id].sorted = {x[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    const vector<int> &L = seg[2 * id].sorted;
    const vector<int> &R = seg[2 * id + 1].sorted;
    int n = L.size(), m = R.size();
    vector<int> &S = seg[id].sorted;
    vector<int> &ll = seg[id].llink, &rr = seg[id].rlink;

    S.resize(n + m);
    ll.resize(n + m);
    rr.resize(n + m);

    int i = 0, j = 0, idx = 0;
    while (i < n && j < m) {
        if (L[i] <= R[j]) {
            S[idx] = L[i];
            ll[idx] = i;
            rr[idx] = j;
            i++;
        } else {
            S[idx] = R[j];
            ll[idx] = i;
            rr[idx] = j;
            j++;
        }
        idx++;
    }
    while (i < n) {
        S[idx] = L[i];
        ll[idx] = i;
        rr[idx] = m;
        i++; idx++;
    }
    while (j < m) {
        S[idx] = R[j];
        ll[idx] = n;
        rr[idx] = j;
        j++; idx++;
    }
}

int countInRange(int id, int a, int b, int c, int d, int lc = -1, int rc = -1) {
    if (seg[id].r < a || seg[id].l > b) return 0;
    if (a <= seg[id].l && seg[id].r <= b) {
        auto lo = lower_bound(seg[id].sorted.begin(), seg[id].sorted.end(), c);
        auto hi = upper_bound(seg[id].sorted.begin(), seg[id].sorted.end(), d);
        return hi - lo;
    }

    if (lc == -1 || rc == -1) {
        auto lo = lower_bound(seg[id].sorted.begin(), seg[id].sorted.end(), c) - seg[id].sorted.begin();
        auto hi = upper_bound(seg[id].sorted.begin(), seg[id].sorted.end(), d) - seg[id].sorted.begin();
        lc = lo;
        rc = hi;
    }

    int left_id = 2 * id, right_id = 2 * id + 1;
    int llo = (lc < seg[id].llink.size() ? seg[id].llink[lc] : seg[left_id].sorted.size());
    int lhi = (rc < seg[id].llink.size() ? seg[id].llink[rc] : seg[left_id].sorted.size());
    int rlo = (lc < seg[id].rlink.size() ? seg[id].rlink[lc] : seg[right_id].sorted.size());
    int rhi = (rc < seg[id].rlink.size() ? seg[id].rlink[rc] : seg[right_id].sorted.size());

    return countInRange(left_id, a, b, c, d, llo, lhi) +
           countInRange(right_id, a, b, c, d, rlo, rhi);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    x.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> x[i];

    build(1, 1, n);

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << countInRange(1, a, b, c, d) << '\n';
    }

    return 0;
}
