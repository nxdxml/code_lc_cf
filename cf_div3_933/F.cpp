/*
    双指针算法
    寻找最靠近最大diff中间的数字
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), c(k), diff(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < m; i ++ ) cin >> b[i];
    for(int i = 0; i < k; i ++ ) cin >> c[i];
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for(int i = 0; i < n - 1; i ++ ){
        diff[i] = a[i + 1] - a[i];
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](auto&& t1, auto&& t2){
        return diff[t1] > diff[t2];
    });
    // 10 15 -> mid = 13
    int ll = a[ord[0]];
    int rr = a[ord[0] + 1];
    // cout << ll << " " << rr << endl;
    int mid = (LL)ll + rr >> 1;
    // cout << "mid=" << mid << endl;
    int ans = diff[ord[0]];
    // cout << ans << endl;
    int lst = n == 2 ? 0 : diff[ord[1]];
    auto check = [&](int i, int j){
        int x = b[i] + c[j];
        if(x <= ll || x >= rr) return ;
        ans = min(ans, max(lst, max(x - ll, rr - x)));
    };
    int j = k - 1;
    for(int i = 0; i < m; i ++ ){
        while(j > 0 && b[i] + c[j - 1] >= mid ) j --;
        check(i, j);
        if(j)check(i, j - 1);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        solve();
    }

    return 0;
}