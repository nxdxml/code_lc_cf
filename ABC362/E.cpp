/*
    dp[i][j][l] 以i为第一个j为第二长度为l的等差数列方案数
    dp[i][j][l] += dp[j][k][l - 1] (i < j < k && 等差)
    从后往前更新
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int MOD = 998244353;
const int N = 85;
int a[N];
int dp[N][N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];

    for(int i = 0; i < n; i ++ ){
        for(int j = i + 1; j < n; j ++ ){
            dp[i][j][2] = 1;
        }
    }
    
    for(int i = n - 1; i >= 0; i -- ){
        for(int j = i + 1; j < n; j ++ ){
            int d = a[j] - a[i];
            for(int k = j + 1; k < n; k ++ ){
                if(a[k] - a[j] != d) continue;
                for(int l = 3; l <= n; l ++ ){
                    dp[i][j][l] = (dp[j][k][l - 1] + dp[i][j][l]) % MOD;
                }
            }
        }
    }
    
    cout << n << " ";
    for(int l = 2; l <= n; l ++ ){
        int ans = 0;
        for(int i = 0; i < n; i ++ ){
            for(int j = i + 1; j < n; j ++ ){
                ans = (ans + dp[i][j][l]) % MOD;
            }
        }
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}