/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    int cnt[4] = {0};
    for(int j = 0; j < 4; j ++ ){
        for(int i = 0; i < n; i ++ ){
            int x;
            cin >> x;
            cnt[j] += x;
        }
    }
    int fg = 0;
    if(cnt[0] > cnt[2]) fg ++ ;
    if(cnt[0] < cnt[2]) fg -- ;
    if(cnt[1] > cnt[3]) fg ++ ;
    if(cnt[1] < cnt[3]) fg -- ;
    if(fg > 1) cout << "A\n";
    else if(fg < -1) cout << "P\n";
    else cout << "DRAW\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}