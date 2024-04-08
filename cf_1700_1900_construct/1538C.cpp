#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;

void solve(){
    int n, L, R;
    cin >> n >> L >> R;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // >= L - a[j]  最小值
    // <= R - a[j]  最大值
    LL ans = 0;

    for(int i = 0; i < n; i ++ ){
        int x = a[i];

        int l1 = 0, r1 = n - 1;
        while(l1 < r1){
            int mid1 = l1 + r1 >> 1;
            if(a[mid1] >= L - x) r1 = mid1;
            else l1 = mid1 + 1;
        }
        int l2 = 0, r2 = n - 1;
        while(l2 < r2){
            int mid2 = l2 + r2 + 1 >> 1;
            if(a[mid2] <= R - x) l2 = mid2;
            else r2 = mid2 - 1;
        }
        if(L - x > a[n - 1] || R - x < a[0]) continue;
        ans += l2 - r1 + 1;
        // cout << l2 << " " << l1 << endl;
        if(r1 <= i && i <= l2) ans --;
    }


    cout << ans / 2 << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T --){
        solve();
    }
    
    

    return 0;
}