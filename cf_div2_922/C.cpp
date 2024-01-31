#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

void solve(){
    LL a, b, r;
    cin >> a >> b >> r;
    if(a < b) swap(a, b);
    bool fg = 0;
    LL ans = 0;
    for(int i = 60; i >= 0; i -- ){
        int x = (a >> i & 1);
        int y = (b >> i & 1);
        LL mask = (1LL << i);
        if(x == y) continue;
        if(mask <= r && fg && x == 1){
            ans -= mask;
            r -= mask;
        } else {
            fg = 1;
            ans += mask * (x - y);
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T;
    cin >> T;
    while (T--)
    {
        /* code */
        solve();
    }
    

    return 0;
}