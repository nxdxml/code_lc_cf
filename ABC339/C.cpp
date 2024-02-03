#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    
    // 0000 1 1111
    LL l = 0, r = 1e18;

    auto check = [&](LL x) -> bool {
        for(int i = 0; i < n; i ++ ){
            x += a[i];
            if(x < 0) return false;
        }
        return true;
    };

    while(l < r){
        LL mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    LL ans = 0;
    for(int i = 0; i < n; i ++ ){
        ans += a[i];
    }
    cout << ans + r << endl;
    return 0;
}