/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = INT_MIN;
    for(int i = 0; i <= 5; i ++ ){
        for(int j = 0; j <= 5; j ++ ){
            for(int k = 0; k <= 5; k ++ ){
                if(i + j + k != 5) continue;
                ans = max(ans, (a + i) * (b + j) * (c + k));
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}