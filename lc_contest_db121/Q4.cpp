// 记忆化搜索数位dp
/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;
long long dp[20][2][2];
long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    string low = to_string(start);
    string high = to_string(finish);
    int n = high.size();
    int diff = n - s.size();
    while(low.size() < n){
        low = "0" + low;
    }

    memset(dp, -1, sizeof dp);

    // cout << "low:" << low << endl;
    // cout << "high:" << high << endl;
    function<long long(int,bool,bool)> dfs = [&](int i, bool limit_low, bool limit_high) -> long long {
        if(i == n) return 1;
        if(dp[i][limit_low][limit_high] != -1) return dp[i][limit_low][limit_high];
        // 第i位数字枚举范围
        int lo = limit_low ? (low[i] - '0') : 0;
        int hi = limit_high ? (high[i] - '0') : 9;
        
        long long res = 0;
        if(i < diff){
            for(int j = lo; j <= min(limit, hi); j ++ ){
                res += dfs(i + 1, limit_low && j == lo, limit_high && j == hi);
            }
        }else {
            int x = s[i - diff] - '0';
            if(lo <= x && x <= min(limit, hi)){
                res = dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
            }
        }
        return dp[i][limit_low][limit_high] = res;
    };
    return dfs(0, true , true);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long start;
    long long finish;
    int limit;
    string s;
    cin >> start >> finish >> limit >> s;
    cout << numberOfPowerfulInt(start, finish, limit, s) << endl;
    

    return 0;
}