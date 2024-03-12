#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int m, n;
    string s;
    cin >> m >> s;
    n = s.size();
    if(n == 1) {
        cout << s << endl;
        return;
    }
    auto check = [&](){
        for(int i = 0; i < n / 2; i ++ ){
            if(s[i] < s[n - i - 1]) return true;
            else if(s[i] > s[n - i - 1]) return false;
        }
        return true;
    };
    if(check()){
        cout << s << endl;
        return;
    }
    string t = s;
    reverse(s.begin(), s.end());
    cout << (s + t) << endl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        solve();
    }

    return 0;
}