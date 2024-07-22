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
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
    }

    map<PII, int> m[3];
    map<tuple<int, int, int> ,int > s;
    LL ans = 0;
    for(int i = 1; i <= n - 2; i ++ ){
        ans += m[0][{a[i], a[i + 1]}] ++ ;
        ans += m[1][{a[i], a[i + 2]}] ++ ;
        ans += m[2][{a[i + 1], a[i + 2]}] ++ ;
        ans -= 3 * s[{a[i], a[i + 1], a[i + 2]}] ++ ;
    }
    // 1 1 2
    // 1 2 2
    // 1 3 2
    // 1 1 2
    // 1 1 2
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