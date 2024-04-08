#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = a[0];
    dp[0][1] = a[0];
    dp[1][0] = min(dp[0][0], 0) + a[1];
    dp[1][1] = max(dp[0][0], 0) + a[1];
    for(int i = 2; i <= n; i ++ ){
        dp[i][0] = min(dp[i - 1][0], dp[i - 2][0]) + a[i];
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][1]) + a[i];
    }
    if(dp[n][0] <= x && dp[n][1] >= x) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}