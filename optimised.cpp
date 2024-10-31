/**
 *    author:  tourist
 *    created: 08.04.2024 10:50:53
**/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector f(n, vector<vector<int>>(m));
    f[0][0].push_back(a[0][0]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        auto& v = f[i][j];
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        vector<int> new_v;
        for (int it = 0; it < int(v.size()); it++) {
          bool bad = false;
          for (int jt = it + 1; jt < int(v.size()); jt++) {
            if (v[jt] % v[it] == 0) {
              bad = true;
              break;
            }
          }
          if (!bad) {
            new_v.push_back(v[it]);
          }
        }
        swap(v, new_v);
        if (i < n - 1) {
          for (int x : v) {
            f[i + 1][j].push_back(__gcd(x, a[i + 1][j]));
          }
        }
        if (j < m - 1) {
          for (int x : v) {
            f[i][j + 1].push_back(__gcd(x, a[i][j + 1]));
          }
        }
      }
    }
    cout << f[n - 1][m - 1].back() << '\n';
  }
  return 0;
}
