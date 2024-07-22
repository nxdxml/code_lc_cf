/*

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
    int a, b;
    cin >> a >> b;
    if(a == b) cout << -1 << endl;
    else {
        for(int i = 1; i <= 3; i ++ ){
            if(i != a && i != b) cout << i << endl;
        }
    }
    

    return 0;
}