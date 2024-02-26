#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n = 7;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int ans = 0;
    for (int p = 0; p < 2; p++) {
      int64_t bad = 0;
      for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
          if ((i + j) % 2 != p) {
            continue;
          }
          if (s[i][j] == 'B' && s[i - 1][j - 1] == 'B' && s[i - 1][j + 1] == 'B' && s[i + 1][j - 1] == 'B' && s[i + 1][j + 1] == 'B') {
            bad |= int64_t(1) << (i * n + j);
          }
        }
      }
      vector<vector<int64_t>> kill(n, vector<int64_t>(n));
      for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
          kill[i][j] |= int64_t(1) << (i * n + j);
          kill[i][j] |= int64_t(1) << ((i - 1) * n + (j - 1));
          kill[i][j] |= int64_t(1) << ((i - 1) * n + (j + 1));
          kill[i][j] |= int64_t(1) << ((i + 1) * n + (j - 1));
          kill[i][j] |= int64_t(1) << ((i + 1) * n + (j + 1));
        }
      }
      int best = n * n + 1;
      for (int t = 0; t < (1 << 13); t++) {
        int at = 0;
        int64_t done = 0;
        for (int i = 1; i < n - 1; i++) {
          for (int j = 1; j < n - 1; j++) {
            if ((i + j) % 2 != p) {
              continue;
            }
            if ((t >> at) & 1) {
              done |= kill[i][j];
            }
            at += 1;
          }
        }
        if ((done & bad) == bad) {
          best = min(best, __builtin_popcount(t));
        }
      }
      ans += best;
    }
    cout << ans << '\n';
  }
  return 0;
}