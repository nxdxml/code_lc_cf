#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 5005;
const int MOD = 998244353;
int dp[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
	cin >> n >> m;
	vector<int> s(n + 1);

	// for(int i = 0; i <= min(n, m + 1); i ++ ) dp[0][i] = 1;
	dp[0][0] = 1;

	for(int i = 1; i <= n; i ++ ) cin >> s[i];
	for(int i = 1; i <= n; i ++ ){
		for(int j = 0; j <= min(n, m + 1); j ++ ){
			if(s[i]) {
				if(j) dp[i][j] = dp[i - 1][j - 1];
			} else {
				// 不同
				if(j) dp[i][j] = (dp[i][j] + (LL)dp[i - 1][j - 1] * (m + 1 - j) % MOD) % MOD;
				// 相同
				dp[i][j] = (dp[i][j] + (LL)dp[i - 1][j] * j % MOD) % MOD;
			}
			// cout << i << " " << j << " " << dp[i][j] << endl; 
		}
	}

	int ans = 0;
	for(int i = 0; i <= min(n, m + 1); i ++ ){
		ans = (ans + dp[n][i]) % MOD;
	}
	cout << ans << endl;
    return 0;
}