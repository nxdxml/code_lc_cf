/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int x = 0;
    for(auto c : s) x += c == '0';
    // cout << x << endl;
    int j = 0;
    LL ans = 0;
    for(int i = 0; i < x; i ++ ){
        while(s[j] != '0') j ++ ;
        if(i != j) ans += j - i + 1;
        j ++ ;
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