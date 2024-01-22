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
    int cnt = 0;

    auto check = [&](int l, int r) -> bool {
        for(int i = l; i <= r; i ++ ){
            for(int j = i + 1; j <= r; j ++ ){
                for(int k = j + 1; k <= r; k ++ ){
                    if(a[j] - a[i] == a[k] - a[j]) return true;
                }
            }
        }
        return false;
    };



    for(int len = 3; len <= 20; len ++ ){
        for(int i = 0; i + len - 1 < n; i ++ ){
            int j = i + len - 1;
            if(!check(i, j)) cnt ++ ;
        }
    }
    
    LL ans = (LL) (n - 1) * (n - 2) / 2;
    ans -= cnt;
    cout << ans << endl;
    return 0;
}