#include <bits/stdc++.h>

using namespace std;

vector<int> arr, brr, crr, tmp;

void Solve() {
  int n;
  cin >> n;
  arr.resize(n);
  brr.clear(), crr.clear();
  brr.reserve((n + 1) >> 1);
  crr.reserve(n >> 1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i & 1) {
      crr.push_back(arr[i]);
    } else {
      brr.push_back(arr[i]);
    }
  }

  auto Parity = [&](vector<int>& axr) {
    tmp.assign(n + 1, 0);
    int res = 0;
    for (int i = 0; i < axr.size(); i++) {
      int x = axr[i], s = 0;
      for (int j = x; j > 0; j -= (j & -j)) {
        s ^= tmp[j];
      }

      res ^= ((i & 1) ^ s);
      for (int j = x; j <= n; j += (j & -j)) {
        tmp[j] ^= 1;
      }
    }
    return res;
  };

  int px = Parity(brr) ^ Parity(crr);
  sort(brr.begin(), brr.end());
  sort(crr.begin(), crr.end());

  if (px) {
    if (n & 1) {
      swap(brr[brr.size() - 1], brr[brr.size() - 2]);
    } else {
      swap(crr[crr.size() - 1], crr[crr.size() - 2]);
    }
  }

  for (int i = 0; i < crr.size(); i++) {
    cout << brr[i] << " " << crr[i] << " ";
  }
  if (n & 1) cout << brr.back();
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
