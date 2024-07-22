/*


*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

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
    int cnt = 0;
    for(int i = 1; i <= n; i ++ ){
        if(z[n - i] >= i){
            cnt ++ ;
        }
    }
    cout << cnt + 1 << endl;
    for(int i = 1; i <= n; i ++ ){
        if(z[n - i] >= i){
            int x = lower_bound(f.begin(), f.end(), i) - f.begin();
            cout << i << " " << n - x + 1 << endl;
        }
    }
    cout << n << " " << 1 << endl;
    return 0;
}