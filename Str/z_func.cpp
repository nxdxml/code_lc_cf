/*
z函数
z[0] = 0;
z[i]表示s与s.substr(i)的最长公共前缀
匹配段(z-box) s[i, i + z[i] - 1]
维护右端点最靠右的匹配段

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;


// 朴素O(n^2)
vector<int> z_func_trivial(string& s){
    int n = (int)s.size();
    vector<int> z(n);
    z[0] = 0;
    for(int i = 1; i < n; i ++ ){
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++ z[i];
    }
    return z;
}

// 线性，利用计算好的z[0]~z[i - 1]
vector<int> z_func(string& s){
    int n = (int)s.size();
    vector<int> z(n);
    z[0] = 0;
    for(int i = 1, l = 0, r = 0; i < n; i ++ ){
            if(i <= r) z[i] = min(z[i - l], r - i + 1);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                l = i;
                r = i + z[i];
                z[i] ++ ;
            }
        // cout << "i=" << i << " z[i]=" << z[i] << " l=" << l << " r=" << r << endl;
    }
    return z;
}

void solve(){
    string s;
    cin >> s;
    auto zz = z_func_trivial(s);
    for(auto x : zz) cout << x << " ";
    cout << endl;
    auto z = z_func(s);
    for(auto x : z) cout << x << " ";
    cout << endl;
    

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T -- ) solve();   
    

    return 0;
}