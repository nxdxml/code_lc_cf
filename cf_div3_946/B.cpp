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
    vector<bool> st(26);
    for(int i = 0; i < n; i ++ ){
        st[s[i] - 'a'] = 1;
    }
    string p = "";
    for(int i = 0; i < 26; i ++ ){
        if(st[i]) p = p + char(i + 'a');
    }
    int pl = p.size();
    unordered_map<char, char> m;
    for(int i = 0; i < pl; i ++ ){
        m[p[i]] = p[pl - 1 - i];
    }
    for(int i = 0; i < n; i ++ ){
        s[i] = m[s[i]];
    }
    cout << s << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}