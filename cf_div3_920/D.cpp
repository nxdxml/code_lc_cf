#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < m; i ++ ) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int i, j;
    LL sum = 0;
    LL ans = 0;
    for(i = 0; i < n; i ++ ){
        sum += abs(a[i] - b[i]);
    }
    ans = sum;
    j = m - 1;
    for(int k = 0; k < n; k ++ ){
        i --;
        sum -= abs(a[i] - b[i]);
        sum += abs(a[i] - b[j]);
        j --;
        
        ans = max(ans, sum);
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