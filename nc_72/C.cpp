// (n - 2) * 26^(n-3)
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
const int mod = 998244353;
const int N = 2e5 + 5;
long long f[N][3][3];
int n, T;


int q_pow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = ((long long)res * a) % mod;
        a = ((long long)a * a) % mod;
        b >>= 1;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 不含010

    f[1][0][0] = 1;
    f[1][0][1] = 1;
    f[1][1][0] = 1;
    f[1][1][1] = 1;

    f[1][2][0] = 24;
    f[1][2][1] = 24;
    f[1][0][2] = 24;
    f[1][1][2] = 24;

    f[1][2][2] = 24 * 24;



    for(int i = 2; i <= 2e5 + 2; i ++ ){
        
        f[i][0][0] = ((long long)f[i-1][0][0] + f[i-1][0][1] + f[i-1][0][2]) % mod;
        f[i][0][1] = ((long long)f[i-1][1][1] + f[i-1][1][2]) % mod;
        f[i][1][0] = ((long long)f[i-1][0][0] + f[i-1][0][1] + f[i-1][0][2]) % mod;
        f[i][1][1] = ((long long)f[i-1][1][0] + f[i-1][1][1] + f[i-1][1][2]) % mod;

        f[i][2][0] = ((long long)f[i-1][0][0] + f[i-1][0][1] + f[i-1][0][2]) * 24 % mod;
        f[i][2][1] = ((long long)f[i-1][1][0] + f[i-1][1][1] + f[i-1][1][2]) * 24 % mod;
        f[i][0][2] = ((long long)f[i-1][2][0] + f[i-1][2][1] + f[i-1][2][2]) % mod;
        f[i][1][2] = ((long long)f[i-1][2][0] + f[i-1][2][1] + f[i-1][2][2]) % mod;

        f[i][2][2] = ((long long)f[i-1][2][0] + f[i-1][2][1] + f[i-1][2][2]) * 24 % mod;


    }

    cin >> T;
    // cout << "T" << T << endl;
    while(T -- ){
        cin >> n;
        if(n <= 2){
            cout << 0 << endl;
            continue;
        }
        long long ans = 0;
        for(int i = 0; i < 3; i ++ ){
            for(int j = 0; j < 3; j ++ ){
                ans += f[n - 1][i][j];
            }
        }
        ans = ans % mod;
        ans = (q_pow(26, n) - ans) % mod + mod;
        cout << ans % mod << endl;

    }
    

    return 0;
}