/*

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
    
    int T;
    cin >> T;
    vector<vector<int>> f(T);
    vector<int> sum(T, 0);
    map<int, PII> m;
    for(int c = 0; c < T; c ++ ){
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++ ) {
            int x;
            cin >> x;
            sum[c] += x;
            f[c].push_back(x);
        }
    }
    bool fg = 1;
    for(int i = 0; i < T; i ++ ){
        for(int j = 0; j < f[i].size(); j ++ ){
            int x = f[i][j];
            if(m.count(sum[i] - x)){
                cout << "YES\n";
                cout << i + 1 << " " << j + 1 << endl;
                cout << m[sum[i] - x].first + 1 << " " << m[sum[i] - x].second + 1 << endl;
                fg = 0;
                break;
            }
        }
        if(fg == 0) break; 
        for(int j = 0; j < f[i].size(); j ++ ){
            int x = f[i][j];
            if(m.count(sum[i] - x)) continue;
            m[sum[i] - x] = {i, j};
        }
    }
    if(fg) cout << "NO\n";

    return 0;
}