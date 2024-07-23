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
    int x;
    cin >> x;
    if(x <= 99) cout << 100 - x;
    else if(x <= 199) cout << 200 - x;
    else if(x <= 299) cout << 300 - x;

    cout << endl;
    

    return 0;
}