/*


*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;


// 朴素O(n^2)

// 线性，利用计算好的z[0]~z[i - 1]
vector<int> z_func(string& s){
    int n = (int)s.size();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i ++ ){
        if(i <= r) z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i;
            r = i + z[i];
            z[i] ++ ;
        }
    }
    return z;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = z_func(s);

    // for(auto x : z) cout << x << " ";
    // cout << endl;
    vector<int> f;
    for(auto x : z){
        f.push_back(x);
    }
    sort(f.begin(), f.end());
    string ans = "Just a legend";
    for(int i = 2; i <= n - 1; i ++ ){
        if(z[i] >= n - i){
            if(++lower_bound(f.begin(), f.end(), z[i]) != f.end()) {
                ans = s.substr(i);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}