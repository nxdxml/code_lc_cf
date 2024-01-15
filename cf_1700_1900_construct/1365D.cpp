// 占领所有坏人身边的空白格子并check
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
const int N = 55;
char g[N][N];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i ++ ){
            cin >> g[i];
        }
        int cnt_G = 0;
        for(int i = 0; i < n; i ++ ){
            for(int j = 0; j < m; j ++ ){
                if(g[i][j] == 'B'){
                    for(int k = 0; k < 4; k ++ ){
                        int x = dx[k] + i;
                        int y = dy[k] + j;
                        if(x < 0 || y < 0 || x >= n || y >= m) continue;
                        if(g[x][y] == '.') g[x][y] = '#';
                    }
                } else if(g[i][j] == 'G') cnt_G ++;
            }
        }
        int c_G = 0, c_B = 0; 
        auto bfs = [&]() -> void {
            vector<vector<bool>> st(n, vector<bool>(m, 0));
            queue<PII> q;
            if(g[n - 1][m - 1] == '#') return;
            q.push({n - 1, m - 1});
            while(!q.empty()){
                auto [x, y] = q.front(); q.pop();
                st[x][y] = 1;
                if(g[x][y] == 'G') c_G ++;
                if(g[x][y] == 'B') c_B ++;
                for(int i = 0; i < 4; i ++ ){
                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                    if(nx < 0 || ny < 0 || nx >= n || ny >=m ) continue;
                    if(g[nx][ny] == '#') continue;
                    if(st[nx][ny]) continue;
                    st[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            return;
        };

        bfs();

        // cout << "c_G " << c_G << endl;
        // cout << "cnt_G " << cnt_G << endl;

        if(c_G == cnt_G && c_B == 0) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    

    return 0;
}