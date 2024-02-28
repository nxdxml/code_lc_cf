#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e5 + 5;
int a[N];
int preSum[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        preSum[i] = a[i] + preSum[i - 1];
    }
    int m;
    cin >> m;
    while(m -- ){
        int L, u;
        cin >> L >> u;
        // preSum[R] - preSum[L - 1] <= u

        auto f = [&](int len){
            // cout <<endl << len << "#"<< (u + u - len) * len / 2 << endl;
            return (LL)((LL)u + u - len + 1) * len / 2;
        };

        int l = L, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(preSum[mid] - preSum[L - 1] <= u) l = mid;
            else r = mid - 1;
        }
        // cout << "l=" << l << endl;
        if(l != n && (f(preSum[l + 1] - preSum[L - 1]) > f(preSum[l] - preSum[L - 1]))){
            cout << l + 1 << " ";
        } else {
            cout << l << " ";
        }
    }
    cout << endl;
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