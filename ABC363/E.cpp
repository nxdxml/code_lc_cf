/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 1005;
int g[N][N];
bool st[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<> > q;
    vector<int> ans(k + 1);
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            cin >> g[i][j];
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                q.push({g[i][j], i, j});
                st[i][j] = 1;
            }
        }
    }
    // pq (h, i, j) 小根堆
    int cur = 0;
    while(!q.empty()){
        auto [h, i, j] = q.top(); q.pop();
        cur = max(cur, h);
        if(cur <= k) ans[cur] ++ ;
        for(int d = 0; d < 4; d ++ ){
            int x = dx[d] + i;
            int y = dy[d] + j;
            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(st[x][y]) continue;
            st[x][y] = 1;
            q.push({g[x][y], x, y});
        }
    }
    for(int i = 2; i <= k; i ++ ){
        ans[i] += ans[i - 1];
    }
    for(int i = 1; i <= k; i ++ ){
        cout << n * m - ans[i] << endl;
    }

    return 0;
}