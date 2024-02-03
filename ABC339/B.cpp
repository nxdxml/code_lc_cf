#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, T;
    cin >> n >> m >> T;
    vector<vector<bool>> st(n, vector<bool>(m, 0));
    int x = 0, y = 0, dir = 0; // upward
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while(T -- ){
        if(st[x][y] == 0){
            st[x][y] = 1;
            dir = (dir + 1) % 4;
        } else {
            st[x][y] = 0;
            dir = (dir - 1 + 4) % 4;
        }
        x = (x + dx[dir] + n) % n;
        y = (y + dy[dir] + m) % m;
    }
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            if(st[i][j])cout << '#';
            else cout << '.';
        }
        cout << endl;
    }

    return 0;
}