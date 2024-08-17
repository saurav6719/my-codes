#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pp pair<int,int>

int query(int r, int c) {
    std::cout << "? " << r << " " << c << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;

    // Query (1, 1)
    

    int k11 = query(1,1);

    // Query (1, m)
    

    int k1m = query(1,m);

    // Query (n, 1)
    

    int kn1 = query(n,1);

    // Calculate possible x and y ranges
    int x1 = k11 + 1;
    int y1 = k11 + 1;

    int x2 = 1 + k1m;
    int y2 = m - k1m;

    int x3 = n - kn1;
    int y3 = 1 + kn1;

    vector<pp> x, y;
    x.push_back({1, x1});
    y.push_back({1, y1});

    x.push_back({1, x2});
    y.push_back({m - y2, m});

    x.push_back({x3, n});
    y.push_back({1, y3});


    pp xrange = {INT_MIN, INT_MAX};
    for (auto ele : x) {
        xrange.first = max(xrange.first, ele.first);
        xrange.second = min(xrange.second, ele.second);
    }

    pp yrange = {INT_MIN, INT_MAX};
    for (auto ele : y) {
        yrange.first = max(yrange.first, ele.first);
        yrange.second = min(yrange.second, ele.second);
    }


    int finalx = -1;
    int finaly = -1;

    // Check for the correct position
    for (int i = xrange.first; i <= xrange.second; i++) {
        if(finalx != -1 and finaly != -1) break;
        for (int j = yrange.first; j <= yrange.second; j++) {
            if (max(i - 1, j - 1) == k11 && max(i - 1, m - j) == k1m && max(n - i, j - 1) == kn1) {
                finalx = i;
                finaly = j;
                break;
            }
        }
    }

    // Output the final result
    std::cout << "! " << finalx << " " << finaly << std::endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
