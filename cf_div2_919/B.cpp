#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;;
    cin >> T;
    while(T -- ){
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n + 1);
        vector<int> pre(n + 1, 0);
        int sum = 0;
        
        for(int i = 1; i <= n; i ++ ){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for(int i = 1; i <= n; i ++ ){
            pre[i] = pre[i - 1] + a[i];
        }
        int ans = INT_MIN;
        for(int i = n; i >= n - k; i -- ){
            ans = max(ans, pre[i] - 2 * (pre[i] - pre[max(0, i - x)]));
        }
        cout << ans << endl;
    }
    

    return 0;
}