#include <bits/stdc++.h>
using namespace std;
const int N = 35;
typedef long long LL;
int a[N];
// LL preSum[N];
int ans, n, m, sep;
// 手写哈希表可过全部数据
unordered_map<int, int > hashMap;
void f(int u, int sum, int cnt){
    if(sum > m || cnt > ans || (hashMap.count(sum) && hashMap[sum] <= cnt)) return;
    if(sum == m) {
        ans = min(ans, cnt);
        return ;
    }
    if(u == sep + 1){
        if(sum <= m){
            if(hashMap.count(sum)){
                hashMap[sum] = min(hashMap[sum], cnt);
            } else {
                hashMap[sum] = cnt;
            }
        }
        return ;
    }
    
    f(u + 1, sum, cnt);
    f(u + 1, sum + a[u] / 2, cnt + 1);
    f(u + 1, sum + a[u], cnt);
}

void dfs(int u, int sum, int cnt){
    if(sum > m || cnt > ans) return;
    if(sum == m) {
        ans = min(ans, cnt);
        return ;
    }
    if(u == n + 1){
        if(hashMap.count(m - sum)){
            ans = min(ans, hashMap[m - sum] + cnt);
        }
        return ;
    }
    
    dfs(u + 1, sum, cnt);
    dfs(u + 1, sum + a[u] / 2, cnt + 1);
    dfs(u + 1, sum + a[u], cnt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ans = INT_MAX;
    cin >> n >> m;
    m <<= 1;
    sep = n / 2;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        a[i] <<= 1;
        // preSum[i] = preSum[i - 1] + a[i];
    }
    sort(a + 1, a + 1 + n);

    f(1, 0, 0);
    dfs(sep + 1, 0, 0);
    if(ans > INT_MAX / 2) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}