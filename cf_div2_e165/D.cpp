/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), ord(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    // b[i] 排序
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return b[i] > b[j];
    });
    // 利润
    LL sum = 0;
    for(int i = 0; i < n; i ++ ){
        sum += max(b[i] - a[i], 0);
    }
    // alice必须买的小于i的最便宜的k件商品价值和
    LL t = 0;

    multiset<int> s;
    LL ans = 0;
    if(k == 0) ans = sum;
    for(auto i : ord){
        sum -= max(0, b[i] - a[i]);
        s.insert(a[i]);
        t += a[i];
        if(s.size() > k){
            t -= *--s.end();
            s.erase(--s.end());
        }
        if(s.size() == k) ans = max(ans, sum - t);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}