#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
// x0 = 0
// x1 = 1
// x2 = a1 - x1 - x0
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<int> b(n);
    
    
    auto check = [&](){
        if(b[0] + b[1] != a[0]) return false;
        for(int i = 2; i < n; i ++ ){
            b[i] = a[i - 1] - b[i - 1] - b[i - 2];
            if(b[i] < 0 || b[i] > 1) return false;
        }
        if(b[n - 1] + b[n - 2] != a[n - 1]) return false;
        return true;
    };

    b[0] = 0;
    b[1] = 0;
    if(check()){
        for(int i = 0; i < n; i ++ ) cout << b[i] << " ";
        return 0;
    }
    b[0] = 0;
    b[1] = 1;
    if(check()){
        for(int i = 0; i < n; i ++ ) cout << b[i] << " ";
        return 0;
    }
    b[0] = 1;
    b[1] = 0;
    if(check()){
        for(int i = 0; i < n; i ++ ) cout << b[i] << " ";
        return 0;
    }
    b[0] = 1;
    b[1] = 1;
    if(check()){
        for(int i = 0; i < n; i ++ ) cout << b[i] << " ";
        return 0;
    }

    return 0;
}