/*
    cnt_sum = (c + 1)*(c + 2) / 2
    cnt_x+y = sum( si / 2 + 1 )
    cnt_y-x = sum()
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 3e5 + 5;
int a[N];
void solve(){
    int n, c;
    cin >> n >> c;
    LL cnt_sum = (LL)(c + 1) * (c + 2) / 2;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    LL cnt_xy = 0;
    LL cnt_yx = 0;
    LL odd = 0, eve = 0;
    for(int i = 0; i < n; i ++ ){
        cnt_xy += a[i] / 2 + 1;
        cnt_yx += c - a[i] + 1;
        if(a[i] % 2) odd ++;
        else eve ++;
    }
    LL cnt_uni = odd + odd * (odd - 1) / 2 + eve + eve * (eve - 1) / 2;
    cout << cnt_sum - cnt_xy - cnt_yx + cnt_uni << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}