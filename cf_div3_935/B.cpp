#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    LL a, b, m;
    cin >> a >> b >> m;
    // ka <= m + 1 找出最大的k
    cout <<  m / a + m / b  + 2 << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}