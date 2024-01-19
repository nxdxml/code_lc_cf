#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int > m;
    for(int i = 0; i < n; i ++ ) cin >> a[i], m[a[i]] ++ ;
    LL ans = 0;
    int t = 0;
    for(auto it : m){
        int x = it.second;
        if(x >= 2) ans += ((LL)x * (x - 1)) / 2 * t;
        if(x >= 3) ans += (LL)x * (x - 1) * (x - 2) / 6;
        t += x;
    }
    cout << ans << endl;

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