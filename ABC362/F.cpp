/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> sz(n + 1, 0);
    for(int i = 0; i < n - 1; i ++ ){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int tc = -1;
    int min_sz = INT_MAX;
    function<void(int, int)> dfs = [&](int u, int fa){
        int mx = 0;
        sz[u] = 1;
        for(int v : g[u]){
            if(v == fa) continue;
            dfs(v, u);
            sz[u] += sz[v];
            mx = max(mx, sz[v]);
        }
        mx = max(mx, n - sz[u]);
        if(mx < min_sz){
            tc = u;
            min_sz = mx;
        }
    };

    dfs(1, -1);

    // cout << "tc = " << tc << endl;

    // for(int i = 1; i <= n; i ++ ) cout << i << "   " << sz[i] << endl;

    vector<int> ans;
    function<void(int, int)> order = [&](int u, int fa){
        ans.push_back(u);
        for(int v : g[u]){
            if(v == fa) continue;
            order(v, u);
        }
    };
    for(int v : g[tc]){
        order(v, tc);
    }
    ans.push_back(tc);
    for(int i = 0; i < n / 2; i ++ ) cout << ans[i] << " " << ans[i + n / 2] << endl;

    

    return 0;
}