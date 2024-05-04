/*
    动态加边并查询节点是否有共用相邻节点，保证是森林
    1 并查集+dfs，小树更新父节点
    2* 树链剖分
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 1e5 + 5;
const int MOD = 998244353;

vector<int> p(N, 0);
vector<int> fa(N, -1);
vector<int> sz(N, 1);
vector<vector<int>> g(N);
int find(int x){
    if(p[x] == x) return p[x];
    return p[x] = find(p[x]);
};
void uni(int x, int y){
    int px = find(x), py = find(y);
    p[px] = py;
    sz[py] += sz[px];
};

void dfs(int u, int fu){
    fa[u] = fu;
    // cout << u << " " << fu << endl;
    for(int v : g[u]){
        if(v == fu) continue;
        dfs(v, u);
    }
};
void merge(int x, int y){
    if(sz[find(x)] > sz[find(y)]) swap(x, y);
    // cout << "x=" << x << " y=" << y << endl;
    dfs(x, y);
    uni(x, y);
    g[x].push_back(y);
    g[y].push_back(x);
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int cnt = 0;

    for(int i = 1; i <= n; i ++ ) p[i] = i;

    int ans = 0;
    for(int i = 0; i < m; i ++ ){
        int a, b, c;
        int A, B, C;
        cin >> a >> b >> c;
        auto encrypt = [&](){
            A = 1 + ((((LL)a * (1 + ans)) % MOD) % 2);
            B = 1 + ((((LL)b * (1 + ans)) % MOD) % n);
            C = 1 + ((((LL)c * (1 + ans)) % MOD) % n);
        };
        encrypt();
        // cout << A << "#" << B << "#" << C << endl;
        // continue;
        if(A == 1){
            merge(B, C);
            continue;
        }
        bool fg = 0;
        
        if(fa[B] == fa[C] && fa[B] != -1) fg = 1, ans = fa[B];
        if(fa[B] != -1 && fa[fa[B]] == C) fg = 1, ans = fa[B];
        if(fa[C] != -1 && fa[fa[C]] == B) fg = 1, ans = fa[C];
        if(!fg) ans = 0;
        cout << ans << endl;
    }
    

    return 0;
}