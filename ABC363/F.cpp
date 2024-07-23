/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

/**
 * x可以分解成的字符串，分解不了返回""
 */
map<LL, string> m_div;
map<LL, LL> m_mul;
string dfs(LL x){
    if(m_div.count(x)) return m_div[x];
    string s = to_string(x);
    int n = s.size();
    bool fg = 1;
    for(int i = 0; i < n; i ++ ){
        if(s[i] != s[n - i - 1] || s[i] == '0') {
            fg = 0;
            break;
        }
    }
    if(fg){
        return m_div[x] = s;
    }
    for(auto e : m_mul){
        if(x % e.second) continue;
        if(dfs(x / e.second) == "") continue;

        return m_div[x] = to_string(e.first) + "*" + dfs(x / e.second) +  "*" + to_string(e.second / e.first);
    }
    return m_div[x] = "";
}

void init(LL n){
    for(LL i = 2; i * i <= n; i ++ ){
        string s = to_string(i);
        reverse(s.begin(), s.end());
        LL j = stoll(s);
        bool fg = 1;
        for(auto e : s){
            if(e == '0'){
                fg = 0;
                break;
            }
        }
        if(fg && (n % (i * j) == 0)) m_mul[i] = i * j;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n;
    cin >> n;
    init(n);
    if(dfs(n) == "") cout << -1 << endl;
    else cout << dfs(n) << endl;
    return 0;
}