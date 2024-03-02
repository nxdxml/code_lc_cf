#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<LL> f;
    auto check = [&](LL x){
        string s = to_string(x);
        int n = s.size();
        for(int i = 0; i < n / 2; i ++ ){
            if(s[i] != s[n - 1 - i]) return false;
        }
        return true;
    };  

    for(LL i = 1; i * i * i <= 1e18; i ++ ){
        if(check(i * i * i)){
            f.push_back(i * i * i);
        }
    }
    int m = f.size();
    LL k; cin >> k;
    int l = 0, r = m - 1;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(f[mid] <= k) l = mid;
        else r = mid - 1;
    }
    cout << f[l] << endl;
    

    return 0;
}