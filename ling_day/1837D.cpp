#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = 0;
    vector<int> ans(n);
    bool fg1 = 1, fg2 = 1;
    for(int i = 0; i < n; i ++ ){
        if(s[i] == '(') t ++ ;
        else t --;
        if(t > 0) ans[i] = 1, fg1 = 0;
        else if(t < 0) ans[i] = 2, fg2 = 0;
        else ans[i] = ans[i - 1];
    }
    if(t != 0) cout << "-1" << endl;
    else {
        if(fg1 | fg2){ // 1
            cout << 1 << endl;
            for(int i = 0; i < n; i ++ ) cout << 1 << " ";
            cout << endl;
        } else {
            cout << 2 << endl;
            for(auto x : ans) cout << x << " ";
            cout << endl;
        }
        
    }
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