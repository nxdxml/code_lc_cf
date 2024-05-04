/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        if(i == n - 1) cout << i << " " << i + 1 << endl;
        else cout << i << " " << i << endl;
    }
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