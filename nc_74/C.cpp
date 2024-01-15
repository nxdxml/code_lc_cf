#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
int T, n, k;

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    cin >> a[i];
    int lst = -2e9;
    for(int i = 1; i <= n; i++) {
    if(lst > a[i] + k) {
        cout << "No\n";
        return;
    }
    lst = max(lst, a[i] - k);
    }
    cout << "Yes\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T -- ){
        solve();
    }
    

    return 0;
}