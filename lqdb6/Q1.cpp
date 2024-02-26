#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        LL x;
        cin >> x;
        if((x % 8) || !x) cout << "No" << endl;
        else {
            cout << "Yes" << endl;
            cout << (x/8) * 2 - 1 << " " << (x/8) * 2 + 1 << endl;
        }
    }

    return 0;
}