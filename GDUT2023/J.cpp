#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// typedef pair<int, PII > PIII;
const int N = 1005;
int n, m, sx, sy;
int g[N][N];
bool st[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> sx >> sy;
    sx --; sy --;
    int max_g = g[sx][sy];
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            cin >> g[i][j];
            max_g = max(max_g, g[i][j]);
        }
    }
    st[sx][sy] = true;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
    long long tol = g[sx][sy];
    int ans = g[sx][sy];
    q.push({g[sx][sy],sx, sy});
    while(!q.empty()){
        auto [t, xx, yy] = q.top(); q.pop();
        // cout << t << endl;
        if(xx == sx && yy == sy);
        else if(t > tol) {
            ans += t - tol;
            tol = 2 * t;
            
        } else {
            tol += t;
        }
        if(tol >= max_g) break;
        for(int i = 0; i < 4; i ++ ){
            int x = dx[i] + xx;
            int y = dy[i] + yy;
            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(st[x][y]) continue;
            st[x][y] = true;
            q.push({g[x][y], x, y});
        }
    }

    if(ans == g[sx][sy]){
        puts({"No cheating need."});
        return 0;
    }
    cout << ans << endl;

    return 0;
}