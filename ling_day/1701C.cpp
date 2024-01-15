
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < m; i ++ ){
        int t;
        cin >> t;
        cnt[t] ++ ;
    }

    // for(int i = 1; i <= n; i ++ ){
        // cout << i << "  " << cnt[i] << endl;
    // }

    auto check = [&](int x) -> bool {
        int t = 0;
        for(int i = 1; i <= n; i ++ ){
            if(cnt[i] >= x) t += x;
            else t += ((x - cnt[i] >> 1) + cnt[i]);
            if(t >= m) return true;
        }
        return false;
    };

    int l = 0, r = 2 * m;
    while(l < r){
        int mid = l + r >> 1;
        // cout << mid << " " << check(mid) << endl;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
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