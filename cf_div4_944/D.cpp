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
    bool fg = 0;
    for(int i = 0; i < n - 1; i ++ ){
        fg |= (s[i] == '0' && s[i + 1] == '1');
    }
    int seg = 1;
    for(int i = 1; i < n; i ++ ){
        if(s[i] != s[i - 1]) seg ++;
    }
    cout << seg - fg << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();

    

    return 0;
}