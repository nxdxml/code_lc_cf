
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 65;
char g[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        cin >> g[i];
    }
    // p1, p2, dist;
    queue<tuple<int, int, int >> q;
    
    auto conv = [&](int i, int j) -> int {
        return i * n + j;
    };

    int p1 = -1, p2 = -1;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            if(p1 == -1 && g[i][j] == 'P'){
                p1 = conv(i, j);
            } else if(g[i][j] == 'P'){
                p2 = conv(i, j);
            }
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    auto walk = [&](int p, int i) -> int {
        int x = p / n;
        int y = p % n;
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx < 0 || ny < 0 || nx >= n || ny >= n || g[nx][ny] == '#'){
            return p;
        }
        return conv(nx, ny);
    };

    q.push({p1, p2, 0});
    vector<vector<bool>> st(n * n, vector<bool>(n * n));
    st[p1][p2] = 1;
    while(!q.empty()){
        auto [x, y, dist] = q.front(); q.pop();
        if(x == y){
            cout << dist << endl;
            return 0;
        }
        for(int i = 0; i < 4; i ++ ){
            int np1 = walk(x, i);
            int np2 = walk(y, i);
            if(st[np1][np2]) continue;
            st[np1][np2] = 1;
            q.push({np1, np2, dist + 1});
        }
    }
    cout << "-1" << endl;
    return 0;
}