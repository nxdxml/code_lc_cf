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
    string s;
    cin >> n >> s;
    int cnt0 = 0;
    int cnt1 = 0;
    if(s[0] == '0') cnt0 ++ ;
    else cnt1 ++ ;
    for(int i = 1; i < n; i ++ ){
        if(s[i] == '1') cnt1 ++ ;
        else {
            if(s[i] != s[i - 1]) cnt0 ++ ;
        }
    }
    if(cnt1 > cnt0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}