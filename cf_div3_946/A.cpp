/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int a, b;
    cin >> a >> b;
    int ans = (b + 1) / 2;
    int x = ans * 7;
    if(b & 1) x += 4;
    if(x >= a){
        cout << ans << endl;
        return ;
    }
    cout << (a - x + 14) / 15 + ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}