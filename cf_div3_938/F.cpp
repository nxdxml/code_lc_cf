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
    while(T -- ) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << a/2 + b/2 + c/2 + d/2 + (a%2==1 && b%2==1 && c%2==1) << endl;
    }
    

    return 0;
}