#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n + 1), b(n + 1), q(Q), ans(Q);
    vector<LL> sum(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ) cin >> b[i];
    for(int i = 0; i < Q; i ++ ) cin >> q[i];
    for(int i = 1; i <= n; i ++ ){
        sum[i] += a[i] + sum[i - 1];
    }
    for(int i = 0; i < Q; i ++ ){
        int k = q[i];
        multiset<int> s;
        LL ans = 1e18;
        LL tol = 0;
        for(int i = 1; i <= n; i ++ ){
            if(i <= k) {
                s.insert(b[i]);
                tol += b[i];
            }
            else {
                tol += b[i];
                s.insert(b[i]);
                tol -= *(--s.end());
                s.erase(--s.end());
            }
            if(i >= k){
                ans = min(ans, sum[i] + tol);
            }
        }
        cout << ans << endl;
    }


    

    return 0;
}