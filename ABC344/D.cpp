#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define SZ(X) ((int)(X).size())
using namespace std;
int dp[101];
void solve() {
    string T;
    cin >> T;
    int N;
    cin >> N;
    for(int i = 1; i <= SZ(T); i++) dp[i] = -1;
    while(N--) {
        int A;
        cin >> A;
        vector<string> ss;
        while(A--) {
            string s;
            cin >> s;
            ss.push_back(s);
        }
        for(int i = SZ(T) - 1; i >= 0; i--) {
            if(dp[i] == -1) continue;
            for(string s: ss) {
                if(i + SZ(s) <= SZ(T) && T.substr(i, SZ(s)) == s) {
                    if(dp[i + SZ(s)] == -1 || dp[i + SZ(s)] > dp[i] + 1) {
                        dp[i + SZ(s)] = dp[i] + 1;
                    }
                }
            }
        }
    }
    cout << dp[SZ(T)] << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
}