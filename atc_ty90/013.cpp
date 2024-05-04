/*
n(1e5)点， m路(1e5)，求1经过k到n的最短路(1<=k<=n)
难度5星

跑两次dijstra
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> g(n);
    for(int i = 0; i < m; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        a -- ;
        b -- ;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    auto dijstra = [&](int start){
        vector<int> dist(n, 0x3f3f3f3f);
        dist[start] = 0;
        priority_queue<PII, vector<PII>, greater<>> q;
        q.push({0, start});
        vector<bool> st(n);
        while(!q.empty()){
            auto [d, t] = q.top(); q.pop();
            if(st[t]) continue;
            st[t] = 1;
            for(auto [u, w] : g[t]){
                dist[u] = min(dist[u], d + w);
                q.push({dist[u], u});
            }
        }
        return dist;
    };
    auto d1 = dijstra(0);
    auto d2 = dijstra(n - 1);

    for(int i = 0; i < n; i ++ ) cout << d1[i] + d2[i] << endl;

    return 0;
}