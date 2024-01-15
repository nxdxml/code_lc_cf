#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

const int N = 15;
const int INF = 1e8;
int g[N][N], f[N][N];

int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
    int m = roads.size();
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            g[i][j] = INF;
        }
    }
    for(int i = 0; i < n; i ++ ) g[i][i] = 0;
    for(auto&& x : roads){
        int a = x[0], b = x[1], c = x[2];
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int ans = (1 << n);
    for(int t = 0; t < (1 << n); t ++ ){
        memcpy(f, g, sizeof f);
        vector<int> S;
        vector <int>().swap(S);
        for(int i = 0; i < n; i ++ ){
            if((t >> i) & 1){
                S.push_back(i);
            }
        }
        int sum = S.size();
        if(sum <= 1) continue;
        for(int i = 0; i < sum; i ++ ){
            for(int j = 0; j < sum; j ++ ){
                for(int k = 0; k < sum; k ++ ){
                    int x = S[i], y = S[j], z = S[k];
                    f[x][y] = min(f[x][y], f[x][z] + f[z][y]);
                }
            }
        }
        bool fg = 0;
        for(int i = 0; i < sum; i ++ ){
            for(int j = 0; j < sum; j ++ ){
                int x = S[i], y = S[j];
                if(f[x][y] > maxDistance){
                    ans --;
                    fg = 1;
                    break;
                }   
            }if(fg) break;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> roads(m, vector<int>(3, 0));
    for(int i = 0; i < m; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        roads[i] = vector<int>{a,b,c};
    }
    cout << numberOfSets(n, k, roads) << endl;

    return 0;
}