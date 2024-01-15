#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// const int N = 1e5 + 5;
int f[26];
map<int, int > m;
bool queryRange(int left, int right) {
    // ----
    // ----
    auto t = m.upper_bound(left);
    if(t == m.end()) return false;
    auto r = t -> first, l = t -> second;
    if(l <= left && r >= right) return true;
    return false;
}
vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& qry) {
    int n = s.size();
    int i = n / 2 - 1;
    int j = n / 2;
    int cnt = 0;
    map<int, int > mp;
    int l = -1, r = -1; 
    int ll, rr;
    bool fg_1 = 1;
    for( ; i >= 0; i --, j ++  ){
        if(cnt == 0 && s[i] == s[j]) continue;
        cnt ++;
        int x = s[i] - 'a', y = s[j] - 'a';
        f[x] ++ , f[y] --;
        bool fg = 1;
        for(int k = 0; k < 26; k ++ ){
            if(f[k]) {fg = 0; break;}
        }
        if(fg) {
            if(fg_1){
                l = i, r = i + cnt - 1;
                fg_1 = 0;
            }
            m[ll] = i + cnt - 1;
            ll = i, rr = i + cnt - 1;
            mp[i] = i + cnt - 1;
            
            cnt = 0;
        }
    }

    
    vector<bool> ans(qry.size(), 1);
    int idx = -1;
    for(auto qq : qry){
        idx ++;
        if(fg_1) continue;
        int a = qq[0];
        int b = qq[1];
        int cc = qq[2];
        int dd = qq[3];
        int c = n - dd - 1;
        int d = n - cc - 1;
        if(min(a, c) > ll || max(b, d) < r) {ans[idx] = 0; continue;}
        if(b <= c - 1 || d <= a - 1){
            ;
        } else {
            int lg, rg;
            if(a < c) lg = b, rg = c;
            else lg = d, rg = c;
            ans[idx] = qeruyRange(lg, rg);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    

    return 0;
}