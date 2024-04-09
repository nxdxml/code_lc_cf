/*
前缀和简单模拟
难度2星

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N][2], s[N][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        int x, y;
        cin >> x >> y;
        x -- ;
        a[i][x] = y;
    }
    for(int i = 1; i <= n; i ++ ){
        s[i][0] = s[i - 1][0] + a[i][0];
        s[i][1] = s[i - 1][1] + a[i][1];
    }
    cin >> m;
    while(m -- ){
        int l, r;
        cin >> l >> r;
        cout << s[r][0] - s[l - 1][0] << " " << s[r][1] - s[l - 1][1] << endl;
    }

    return 0;
}