/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
vector<int> z_func(string& s){
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i ++ ){
        if(i <= r) z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            l = i;
            r = i + z[i];
            z[i] ++ ;
        }
    }
    return z;
}

void solve(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    string s;
    cin >> s;

    vector<int> z = z_func(s);
    // for(auto x : z) cout << x << " ";
    // cout << endl;
    vector<int> ans(n + 1);
    int E = (int)sqrt(n);
    for(int k = 1; k <= E; k ++ ){
        auto check = [&](int x){
            int cnt = 1;
            for(int i = x; i < n; i ++ ){
                if(z[i] >= x){
                    cnt ++ ;
                    if(cnt >= k) return true;
                    i += x - 1;
                }
            }
            return cnt >= k;
        };
        int l = 0, r = n;
        // 1111 1 0000
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        // cout << l << endl;
        ans[k] = l;
        // cout << k << " " << l << endl;
    }
    for(int x = 1; x <= E; x ++ ){
        int cnt = 1;
        for(int i = x; i < n; i ++ ){
            if(z[i] >= x){
                cnt ++ ;
                i += x - 1;
            }
        }
        ans[cnt] = max(ans[cnt], x);
    }
    for(int i = n - 1; i >= 1; i -- ) ans[i] = max(ans[i], ans[i + 1]);

    for(int i = k1; i <= k2; i ++ ) cout << ans[i] << " ";
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