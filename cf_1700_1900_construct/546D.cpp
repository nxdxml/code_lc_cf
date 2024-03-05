// 统计因子个数和
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 5e6 + 5;
int f[N];
int init = [](){
    f[1] = f[2] = 0;
    for(int i = 2; i < N ; i ++ ){
        if(f[i]) continue;
        for(int j = i; j < N; j += i ) f[j] = f[j / i] + 1;
    }
    for(int i = 2; i < N; i ++ ) f[i] += f[i - 1];
    return 0;
}();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        int l, r;
        cin >> r >> l;
        cout << f[r] - f[l] << endl;
    }
    

    return 0;
}