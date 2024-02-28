#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e5 + 5;
int dep[N], dp[N][21], s[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> g(n + 1);

    for(int i = 0; i < n - 1; i ++ ){
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, i + 1});
        g[y].push_back({x, i + 1});
    }

    function<void(int, int )> dfs = [&](int u, int fa){
        dep[u] = dep[fa] + 1;
        dp[u][0] = fa;

        for(int i = 1; i <= 20; i ++ ){
            dp[u][i] = dp[dp[u][i - 1]][i - 1];
        }

        for(auto&& [v, id] : g[u]){
            if(v == fa) continue;
            dfs(v, u);
        }
    };
    dfs(1, 0);

    function<int(int, int )> lca = [&](int x, int y){
        if(dep[x] < dep[y]) swap(x, y);
        for(int i = 20; i >= 0; i -- ){
            if(dep[dp[x][i]] >= dep[y]){
                x = dp[x][i];
            }
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

    for(int i = 0; i < m; i ++ ){
        int x, y;
        cin >> x >> y;
        // cout << lca(x, y) << endl;
        s[x] ++, s[y] ++ , s[lca(x, y)] -= 2;
    }

    int ans = -1;

    function<void(int, int )> get_ans = [&](int u, int fa){
        for(auto&& [v, id] : g[u]){
            if(v == fa) continue;
            get_ans(v, u);
            s[u] += s[v];
            if(s[v] == m) ans = max(ans, id);
        }
    };
    get_ans(1, 0);
    cout << ans << endl;

    return 0;
}