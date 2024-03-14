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
    int cnt1 = 0, cnt2 =0;
    for(int i = 0; i < n - 2; i ++ ){
        if(s.substr(i, 3) == "map" || s.substr(i, 3) == "pie") cnt1 ++ ;
        if(i < n - 4)if(s.substr(i, 5) == "mapie") cnt2 ++ ;
    }
    cout << cnt1 - cnt2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}