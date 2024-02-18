#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;

int f[25];

void divd(int x){
    int idx = 0;
    while(x){
        if(x & 1) f[idx] ++ ;
        x >>= 1;
        idx ++ ;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int y = 0;
    for(int i = 1; i <= n; i ++ ){
        int x;
        cin >> x;
        y ^= x;
        divd(y);
    }
    LL ans = 0;
    for(int i = 0; i < 21; i ++ ){
        ans += (LL)(1 << i) * f[i] * (n - f[i] + 1);
    }
    cout << ans << endl;
    return 0;
}


// const int N = 1e5 + 5;
// int a[N];


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n; cin >> n;
//     for(int i = 1; i <= n; i ++ ){
//         cin >> a[i];
//         a[i] ^= a[i - 1];
//     }
//     LL ans = 0;
//     LL t = 1;
//     for(int j = 0; j < 21; j ++ ){
//         vector<LL> cnt(2, 0);
//         cnt[0] = 1;
//         for(int i = 1; i <= n; i ++ ){
//             int x = (a[i] >> j) & 1;
//             ans += t * cnt[x ^ 1]; 
//             cnt[x] ++;
//         }
//         t *= 2;
//     }
//     cout << ans << endl;
//     return 0;
// }