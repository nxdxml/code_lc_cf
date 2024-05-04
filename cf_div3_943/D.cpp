/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
LL p[N], a[N];

void solve(){
    LL n, k, s1, s2;
    cin >> n >> k >> s1 >> s2;
    for(int i = 1; i <= n; i ++ ) cin >> p[i];
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    // k = min(k, n);

    LL c1 = 0;
    LL preSum1 = 0;
    for(LL i = 1; i <= min(n, k); i ++ ){
        preSum1 += a[s1];
        c1 = max(c1, preSum1 + a[s1] * (k - i));
        s1 = p[s1];
    }
    LL c2 = 0;
    LL preSum2 = 0;
    for(LL i = 1; i <= min(n, k); i ++ ){
        preSum2 += a[s2];
        c2 = max(c2, preSum2 + a[s2] * (k - i));
        s2 = p[s2];
    }
    // cout << c1 << " " << c2 << endl;
    if(c1 > c2) cout << "Bodya\n";
    else if(c1 < c2) cout << "Sasha\n";
    else cout << "Draw\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}