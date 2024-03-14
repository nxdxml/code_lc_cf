#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> g(n, vector<int>(m, 0));
    vector<vector<LL>> dp(n, vector<LL>(m, 0));

    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < m; j ++ )
            cin >> g[i][j];

    for(int i = 0; i < n; i ++ ){
        dp[i][0] = 1;
        deque<int> q;
        q.push_back(0);
        for(int j = 1; j < m; j ++ ){
            dp[i][j] = dp[i][q.front()] + g[i][j] + 1;
            // cout << i << " " << j << " " << dp[i][j] << endl;
            if(j - q.front() >= d + 1) q.pop_front();
            while(!q.empty() && dp[i][j] <= dp[i][q.back()]) q.pop_back();
            q.push_back(j);
        }
        // cout << i << " " << dp[i][m - 1] << endl;
    }
    LL ans = 1e18;
    for(int i = 0; i <= n - k; i ++ ){
        LL sum = 0;
        for(int j = i; j < i + k; j ++ ){
            sum += dp[j][m - 1];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // dp[0] = 0
    // dp[i] = min(dp[i - 1] ... dp[i - d]) + 1;
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}