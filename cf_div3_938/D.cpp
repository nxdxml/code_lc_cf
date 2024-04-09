#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N], b[N];
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    map<int, int > mp;
    for(int i = 0; i < m; i ++ ) {
        cin >> b[i];
        mp[b[i]] ++ ;
    }
    map<int, int > cnt;
    int t = 0;
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        cnt[a[i]] ++ ;
        if(mp.count(a[i]) && mp[a[i]] >= cnt[a[i]]) t ++ ;
        if(i >= m) {
            cnt[a[i - m]] --;
            if(mp.count(a[i - m]) && mp[a[i - m]] > cnt[a[i - m]]) t --;
        }
        if(i >= m - 1) ans += t >= k;
    }
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