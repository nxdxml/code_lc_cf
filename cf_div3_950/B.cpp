/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 105;
int a[N];
void solve(){
    int n, f, k;
    cin >> n >> f >> k;
    // cout << "n=" << n << endl;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int x = a[f - 1];
    sort(a, a + n, [&](const auto& t1, const auto& t2){
        return t1 > t2;
    });

    // for(int i = 0; i < n; i ++ ) cout << a[i] << endl;
    // cout << endl;

    if(k == n | a[k] < x){
        cout << "YES" << endl;
        return ;
    }
    if(a[k - 1] > x){
        cout << "NO" << endl;
        return ;
    }
    cout << "MAYBE" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}