#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e5 + 5;

struct node{
    int p, k;
}f[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        cin >> f[i].p >> f[i].k;
    }
    sort(f, f + n, [](auto &t1, auto &t2){return t1.p < t2.p;});

    vector<int> dp(n);
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        auto [p, k] = f[i];
        int x = p - k;
        // 找到>=x的第一个数字
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(f[mid].p >= x) r = mid;
            else l = mid + 1;
        }
        if(f[0].p >= x) dp[i] = 1;
        else dp[i] = dp[r - 1] + 1;
        ans = max(ans, dp[i]);
    }
    cout << n - ans << endl;

    return 0;
}