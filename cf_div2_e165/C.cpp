/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 3e5 + 5;

LL a[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];

    // 前i个数字，已经使用了j次操作的最小值
    vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, 1e18));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0; j <= k; j ++ ){
            LL x = a[i];
            for(int len = 0; len + j <= k && i + len <= n ; len ++ ){
                x = min(x, a[i + len]);
                dp[i + len][len + j] = min(dp[i + len][len + j], dp[i - 1][j] + x * (len + 1));
            }
        }
    }
    LL ans = 1e18;
    for(int i = 0; i <= k; i ++ ) ans = min(ans, dp[n][i]);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();

    

    return 0;
}