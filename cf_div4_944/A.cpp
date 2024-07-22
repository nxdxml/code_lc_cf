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
    int T;
    cin >> T;
    while(T -- ){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        cout << x << " " << y << endl;
    }
    

    return 0;
}