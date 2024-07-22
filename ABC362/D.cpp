/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using PLI = pair<long long, int >;
using LL = long long;
const int N = 2e5 + 5;
LL dist[N];
LL val[N];
bool st[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<PLI>> g(n + 1);
    for(int i = 1; i <= n; i ++ ){
        cin >> val[i];
        dist[i] = 1e18;
    }
    for(int i = 1; i <= m; i ++ ){
        int a, b;
        LL c;
        cin >> a >> b >> c;
        g[a].push_back({c + val[b], b});
        g[b].push_back({c + val[a], a});
    }
    dist[1] = 0;
    memset(st, 0, sizeof st);
    priority_queue<PLI, vector<PLI>, greater<> > q;
    q.push({dist[1], 1});
    while(!q.empty()){
        auto [d, u] = q.top();
        q.pop();
        if(st[u]) continue;
        st[u] = 1;
        
        for(auto [x, v] : g[u]){
            if(dist[v] > dist[u] + x){
                dist[v] = dist[u] + x;
                q.push({dist[v], v});
            }
        }
    }

    for(int i = 2; i <= n; i ++ ){
        cout << dist[i] + val[1] << " ";
    }
    cout << endl;
    return 0;
}