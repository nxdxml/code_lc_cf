#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m, 0));
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            cin >> g[i][j];
            // cout << i << j << g[i][j] << endl;
        }
    }

    // cout<< "$" << endl;
    // return ;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<PII> q;
    q.push({0, 0});
    dist[0][0] = 0;
    // 相对运动 终点相当于在相对图中向下运动
    
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        // cout << x << " " << y << endl;
        // 右 (x + 1, y + 1)
        int nx, ny;
        nx = (x + 1) % n, ny = (y + 1) % m;
        if(y < m - 1 && dist[nx][ny] == -1 && g[nx][ny] == 0) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
        nx = (x + 2) % n, ny = y;        
        if(dist[nx][ny] == -1 && g[nx][ny] == 0 && g[(x + 1) % n][ny] == 0) {
            dist[nx][ny] = dist[x][y] + 1; 
            q.push({nx, ny});
        }
    }
    int ans = -1;
    // return ;
    for(int i = 0; i < n; i ++ ){
        int t = dist[i][m - 1];
        if(t == -1) continue;
        int pos = (t - 1 + n) % n;
        if(pos > i) t += n - pos + i;
        else t += i - pos;
        if(ans == -1 || ans > t) ans = t;
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