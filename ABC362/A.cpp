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
    int x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    if(s[0] == 'R') cout << min(y, z);
    else if(s[0] == 'G') cout << min(x, z);
    else cout << min(x, y);
    cout << endl;
    

    return 0;
}