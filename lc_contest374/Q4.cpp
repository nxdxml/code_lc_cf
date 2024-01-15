// C(s,m1) * C(s-m1,m2) * ... * C(s-m1-...-m_{k-1},m_{k}) * 2^(m1 + m2 +... M_{k} - k)
// * - - - *
// LL LR RR RL + (L/R) -> 2^(m - 1)
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;


const int MOD = 1'000'000'007;
const int MX = 100'000;

long long q_pow(long long x, int n) {
    long long res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

// 组合数模板
long long fac[MX], inv_fac[MX];

auto init = [] {
    fac[0] = 1;
    for (int i = 1; i < MX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[MX - 1] = q_pow(fac[MX - 1], MOD - 2);
    for (int i = MX - 1; i > 0; i--) {
        inv_fac[i - 1] = inv_fac[i] * i % MOD;
    }
    return 0;
}();

long long comb(int n, int k) {
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}

int numberOfSequence(int n, vector<int>& f) {
    int m = f.size();
    // 处理边界
    int s = n - m;
    long long ans = comb(s, f[0]) * comb(s - f[0], n - f[m - 1]- 1) % MOD;
    s -= f[0] + n - f[m - 1] - 1;
    for(int i = 1; i < m; i ++ ){
        int len = f[i] - f[i - 1] - 1;
        if(len == 0) continue;
        ans = (ans * comb(s, len) % MOD * q_pow(2, len - 1)) % MOD;
        s -= len;
    }
    return ans;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> sick(m, 0);
    for(int i = 0; i < m; i ++ ){
        cin >> sick[i];
    }
    cout << numberOfSequence(n, sick) << endl;
    

    return 0;
}