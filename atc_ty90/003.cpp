/*
树上加一条边求最大环
n <= 1e5
难度4星

树的直径
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int d[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < n - 1; i ++ ){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    function<void(int,int)> dfs = [&](int u, int fa){
        d[u] = d[fa] + 1;
        for(auto v : g[u]){
            if(v == fa) continue;
            dfs(v, u);
        }
    };
    dfs(1, 0); 
    int p = 1;
    for(int i = 1; i <= n; i ++ ) {
        if(d[i] > d[p]) p = i;
    }
    memset(d, 0, sizeof d);
    dfs(p, 0);
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        if(d[i] > ans) ans = d[i];
    }
    cout << ans << endl;
    return 0;
}