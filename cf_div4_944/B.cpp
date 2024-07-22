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
    if(n == 1) {
        cout << "NO" << endl;
        return ;
    }
    for(int i = 1; i < n; i ++ ){
        if(s[i] != s[0]){
            cout << "YES" << endl;
            char t = s[0];
            s[0] = s[i];
            s[i] = t;
            cout << s << endl;
            return ;
        }
    }
    cout << "NO" << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}