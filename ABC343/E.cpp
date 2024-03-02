#define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const multiset<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

template <class T> auto vect(const T& v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
  return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}

using int64 = long long;
using int128 = __int128_t;
using ii = pair<int, int>;
#define SZ(x) (int)((x).size())
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
mt19937_64 mrand(random_device{}());
int64 rnd(int64 x) { return mrand() % x; }
constexpr inline int lg2(int64 x) { return x == 0 ? -1 : sizeof(int64) * 8 - 1 - __builtin_clzll(x); }
constexpr inline int64 p2ceil(int64 x) { return 1LL << (lg2(x - 1) + 1); }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < SZ(a); ++i) cout << a[i] << " \n"[i + 1 == SZ(a)]; }
template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> void dedup(vector<T>& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
inline void add_mod(int& x, int y) { x += y; if (x >= MOD) x -= MOD; }
inline void sub_mod(int& x, int y) { x += MOD - y; if (x >= MOD) x -= MOD; }
inline int mod(int x) { return x >= MOD ? x - MOD : x; }

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

int main() {
  int V1, V2, V3;
  cin >> V1 >> V2 >> V3;
  vector<array<int, 3>> a(3);
  a[0] = {0, 0, 0};
  vector<array<int, 3>> can;
  for (int x = -7; x <= 7; ++x) {
    for (int y = -7; y <= 7; ++y) {
      for (int z = -7; z <= 7; ++z) {
        can.push_back({x, y, z});
      }
    }
  }
  auto get =
    [&](const array<int, 3>& a) {
      return 7 * 7 * 7;
    };
  auto get2 =
    [&](const array<int, 3>& a, const array<int, 3>& b) {
      int ret = 1;
      for (int k = 0; k < 3; ++k) {
        int L = max(a[k], b[k]), R = min(a[k] + 7, b[k] + 7);
        ret = ret * max(0, R - L);
      }
      return ret;
    };
  auto get3 =
    [&](const array<int, 3>& a, const array<int, 3>& b, const array<int, 3>& c) {
      int ret = 1;
      for (int k = 0; k < 3; ++k) {
        int L = max({a[k], b[k], c[k]}), R = min({a[k] + 7, b[k] + 7, c[k] + 7});
        ret = ret * max(0, R - L);
      }
      return ret;
    };

  for (auto v1 : can) {
    a[1] = v1;
    for (auto v2 : can) {
      a[2] = v2;
      int W3 = get3(a[0], a[1], a[2]);
      int W2 = get2(a[0], a[1]) + get2(a[1], a[2]) + get2(a[2], a[0]);
      int W1 = get(a[0]) + get(a[1]) + get(a[2]);
      W2 -= 3 * W3;
      W1 -= 2 * W2 + 3 * W3;
      if (W1 == V1 && W2 == V2 && W3 == V3) {
        cout << "Yes" << '\n';
        vector<int> v;
        for (int i = 0; i < 3; ++i) {
          for (int j = 0; j < 3; ++j) {
            v.push_back(a[i][j]);
          }
        }
        out(v);
        return 0;
      }
    }
  }
  cout << "No" << '\n';
  return 0;
}
