/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int x;
    cin >> x;
    int t = 0;
    int ans;
    for(int i = 1; i < x; i ++ ){
        int y = __gcd(i, x);
        if(y + i > t){
            t = y + i;
            ans = i;
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