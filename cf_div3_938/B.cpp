#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 250005, M = 505;
int a[N], f[N];
int b[M][M];
bool solve(){
    int n, c, d;
    cin >> n >> c >> d;
    for(int i = 0; i < n * n; i ++ ) cin >> a[i];
    sort(a, a + n * n);
    b[0][0] = a[0];
    int idx = 0;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            if(i) b[i][j] = b[i - 1][j] + c;
            if(j) b[i][j] = b[i][j - 1] + d;
            f[idx ++ ] = b[i][j];
        }
    }
    sort(f, f + n * n);
    for(int i = 0; i < n * n; i ++ ){
        if(a[i] != f[i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T -- ) {
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    

    return 0;
}