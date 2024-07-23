/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 105;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, T, P;
    cin >> n >> T >> P;
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    sort(a, a + n, [](const auto t1, const auto t2){
        return t1 > t2;
    });
    if(a[P - 1] >= T) cout << 0 << endl;
    else cout << T - a[P - 1] << endl;
    return 0;
}