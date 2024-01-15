#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        if(n % i) continue;
        int t = 0;
        for(int j = 0; j + i < n; j ++ ){
            t = __gcd(t, abs(a[j] - a[j + i]));
        }
        ans += (t != 1);
    }
    cout << ans << endl;
    return ;
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