#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef pair<char, char > PCC;
typedef pair<PCC, int> PCCI;
const int N = 1e5 + 5;
const int MOD = 998244353;
int n, m;


const int MX = 505;
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

int dp[30][30][505];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> n >> s >> m;
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i ++ ){
        for(int j = i + 1; j < n; j ++ ){
            int len = j - i - 1;
            int a = s[i] - 'a';
            int b = s[j] - 'a';
            for(int k = 0; k <= len; k ++ ){
                dp[a][b][k] = (dp[a][b][k] + comb(len, k)) % MOD;
            }            
        }
    }
    for(int i = 0; i < m; i ++ ){
        char a, b;
        int len;
        cin >> a >> b >> len;
        cout << dp[a - 'a'][b - 'a'][len - 2] << endl;
    }


    return 0;
}