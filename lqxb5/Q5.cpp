#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL x;
    cin >> x;
    LL t = (LL)floor(sqrt(x));
    // cout << "len=" << t << endl;
    LL ans = 4 * (t - 2) * (t - 2) + 2 * 4 + 4 * 3 * (t - 2);

    LL delta = x - t * t;
    if(delta <= t && delta > 0) {
        ans += delta * 4 - 2;
    } else if(delta > 0) {
        ans += delta * 4 - 4;
    }
    cout << ans << endl;
    return 0;
}