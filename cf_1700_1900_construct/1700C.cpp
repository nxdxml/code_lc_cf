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
    LL ans = 0;
    LL t = 0;
    cin >> a[1];
    for(int i = 2; i <= n; i ++ ){
        cin >> a[i];
        int d = a[i] - a[i - 1];
        
        // 往前面减，汇集到a[1];
        if(d < 0) t += d;
        
        if(d < 0) ans += -d;
        else ans += d;
    }
    cout << ans + abs(t + a[1]) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 9 2 3 4 5 6
    //9 -7 1 1 1 1

    int T;
    cin >> T;
    while(T -- ){
        solve();
    }
    

    return 0;
}