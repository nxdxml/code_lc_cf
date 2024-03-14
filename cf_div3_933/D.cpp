#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, m, kk;
    cin >> n >> m >> kk;
    vector<vector<bool>> st(m + 1, vector<bool>(n, 0));
    st[0][-- kk] = 1;
    for(int i = 1; i <= m; i ++ ){
        int x;
        char y;
        cin >> x >> y;
        for(int j = 0; j < n; j ++ ){
            if(st[i - 1][j]){
                if(y != '1') st[i][(j + x) % n] = 1;
                if(y != '0') st[i][((j - x) % n + n) % n] = 1;
                
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++ ) ans += st[m][i];
    cout << ans << endl;
    for(int i = 0; i < n; i ++ ) {
        if(st[m][i]) cout << i + 1 << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}