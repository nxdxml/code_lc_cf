#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < m; i ++ ) cin >> b[i];
    int ans = 0;
    for(auto x : a)
        for(auto y : b){
            ans += ((x + y) <= k);
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