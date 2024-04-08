#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    LL ans = a;
    if((3 - (b % 3)) % 3 > c){
        cout << -1 << endl;
        return ;
    }
    ans += (b + c) / 3;
    ans += ((b + c) % 3 + 1) / 2;
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