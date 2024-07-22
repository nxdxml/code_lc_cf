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
    int n;
    cin >> n >> s;
    int x = 0, y = 0;
    for(int i = 0; i < n; i ++ ){
        if(s[i] == 'N') x ++ ;
        if(s[i] == 'S') x -- ;
        if(s[i] == 'W') y -- ;
        if(s[i] == 'E') y ++ ; 
    }
    if((x & 1) || (y & 1)){
        cout << "NO" << endl;
        return ;
    }
    if(n == 2 && x == 0 && y == 0){
        cout << "NO" << endl;
        return ;
    }
    stringstream ss;
    for(int i = 0; i < n; i ++ ){
        ss << "R";
    }
    string ans = ss.str();
    if(x == 0 && y == 0){
        ans[0] = 'H';
        map<char, char> m;
        m['S'] = 'N';
        m['N'] = 'S';
        m['W'] = 'E';
        m['E'] = 'W';
        for(int i = 1; i < n; i ++ ){
            if(m[s[i]] == s[0]){
                ans[i] = 'H';
                break;
            }
        }
    } else {
        for(int i = 0; i < n; i ++ ){
        if(s[i] == 'N' && x > 0) ans[i] = 'H', x -= 2;
        if(s[i] == 'S' && x < 0) ans[i] = 'H', x += 2;
        if(s[i] == 'E' && y > 0) ans[i] = 'H', y -= 2;
        if(s[i] == 'W' && y < 0) ans[i] = 'H', y += 2;
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