#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 105;
int g[N][N];
bool st[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    memset(st, 0, sizeof st);
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            cin >> g[i][j];
            if(g[i][j]) st[i] = 1;
        }
    }
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            if(g[i][j]) cout << j + 1 << " ";
        }
        if(st[i]) cout << endl;
    }

    return 0;
}