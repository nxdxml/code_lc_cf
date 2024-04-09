/*
从1e5字符串选子串有多少个atcoder,答案MOD 1e9+7
难度4星

简单dp
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    map<string, int> m;
    m["a"] = 0;
    m["at"] = 0;
    m["atc"] = 0;
    m["atco"] = 0;
    m["atcod"] = 0;
    m["atcode"] = 0;
    for(int i = 0; i < n; i ++ ){
        if(s[i] == 'a') m["a"] = (m["a"] + 1) % MOD;
        else if(s[i] == 't') m["at"] = (m["a"] + m["at"]) % MOD;
        else if(s[i] == 'c') m["atc"] = (m["at"] + m["atc"]) % MOD;
        else if(s[i] == 'o') m["atco"] = (m["atc"] + m["atco"]) % MOD;
        else if(s[i] == 'd') m["atcod"] = (m["atco"] + m["atcod"]) % MOD;
        else if(s[i] == 'e') m["atcode"] = (m["atcod"] + m["atcode"]) % MOD;
        else if(s[i] == 'r') ans = (ans + m["atcode"]) % MOD;
    }
    cout << ans << endl;
    return 0;
}