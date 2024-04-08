#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b (n + 1);
    vector<LL> s(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ) cin >> b[i];
    for(int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + min(a[i], b[i]);
    LL ans = 1e18;
    for(int i = 1; i <= m && i <= n; i ++ ){
        ans = min(ans, a[i] + (s[n] - s[i]));
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T ;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}