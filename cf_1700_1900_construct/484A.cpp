/*
    从l开始把小于r的每一位都变成1
*/

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    while(n -- ){
        LL l, r;
        cin >> l >> r;
        LL t = l;
        LL x = r;
        int y = 0;
        while(r){
            if(l % 2 == 0){
                if(t + (1LL << y) > x) break;
                else t += (1LL << y);
            }
            y ++ ;
            r >>= 1;
            l >>= 1;
        }
        cout << t << endl;
    }

    return 0;
}