/*

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
    LL ans = 0;
    for(int i = n; i >= k; i -- ) {
        cout << i << " ";
    }
    for(int i = m + 1; i <= k - 1; i ++ ) {
        cout << i << " ";
    }
    for(int i = 1; i <= m; i ++ ){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}