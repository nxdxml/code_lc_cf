/*
两个数组任意排列相差值的最小值
难度3星

排序
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
    LL ans = 0;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i ++ ){
        ans += abs(a[i] - b[i]);
    }
    cout << ans << endl;
    

    return 0;
}