/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N];


void solve(){
    int n, k;
    cin >> k >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n - 1; i ++ ){
        ans += 2 * a[i] - 1;
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