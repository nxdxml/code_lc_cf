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
    vector<int> a(n + 1);
    unordered_map<LL, int> m;
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        ans += (++m[(LL)a[i] * i] - 1);
    }
    cout << ans << endl;
    

    return 0;
}