#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e5 + 5;
int dep[N], f[N];
int dp[N][21]; // 从i开始跳2^j可到达的点

LL dist[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> g(n + 1);
    for(int i = 0; i < n - 1; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    // return 0;
    function<void(int,int)> dfs = [&](int u, int fa){
        dep[u] = dep[fa] + 1;
        dp[u][0] = fa;
        for(int i = 1; i <= 20; i ++ ){
            dp[u][i] = dp[dp[u][i - 1]][i - 1];
        }
        for(auto&& [v, d] : g[u]){
            if(v == fa) continue;
            dist[v] = dist[u] + d;
            dfs(v, u);
        }
    };
    dfs(1, 0);
    auto lca = [&](int x, int y){
        if(dep[x] < dep[y]) swap(x, y);
        for(int i = 20; i >= 0; i -- ){
            if(dep[dp[x][i]] >= dep[y]) x = dp[x][i];
        }
        if(x == y) return x;
        for(int i = 20; i >= 0; i -- ){
            if(dp[x][i] != dp[y][i]){
                x = dp[x][i];
                y = dp[y][i];
            }
        }
        return dp[x][0];
    };

    auto get_dist = [&](int x, int y) -> LL {
        if(x == 0 || y == 0) return 0;
        return dist[x] + dist[y] - 2LL * dist[lca(x, y)];
    };

    for(int i = 1; i <= m; i ++ ) cin >> f[i];
    LL sum = 0;
    for(int i = 1; i <= m; i ++ ){
        sum += get_dist(f[i - 1], f[i]);
        // cout << get_dist(f[i - 1], f[i]) << endl;
    }
    // cout << "sum=" << sum << endl;
    for(int i = 1; i <= m; i ++ ){
        LL d1 = get_dist(f[i - 1], f[i]);
        LL d2 = get_dist(f[i], f[i + 1]);
        LL d3 = get_dist(f[i - 1], f[i + 1]);
        cout << sum - d1 - d2 + d3 << " ";
    }
    cout << endl;
    // for(int i = 1; i <= n; i ++ ){
    //     cout << dist[i] << endl;
    // }
    return 0;
}