/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 3e5 + 5;
const int L = 25;
LL f[N][L];
void solve(){
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];

    for(int i = 0; i < n - 1; i ++ ){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    function<void(int, int)> dfs = [&](int u, int fa){
        for(int i = 1; i < L; i ++ ) f[u][i] = a[u] * i; 
        for(auto v : g[u]){
            if(v == fa) continue;
            dfs(v, u);
            for(int i = 1; i < L; i ++ ){
                LL t = LLONG_MAX;
                for(int j = 1; j < L; j ++ ){
                    if(j == i) continue;
                    t = min(t, f[v][j]);
                }
                f[u][i] += t;
            }
        }
    };

    dfs(1, -1);
    LL ans = LLONG_MAX;
    for(int i = 1; i < L; i ++ ){
        ans = min(ans, f[1][i]);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}