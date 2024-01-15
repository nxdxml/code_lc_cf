#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// const int N = 1e5 + 5;
int T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T -- ){
        int n, m, X, Y;
        cin >> n >> m >> X >> Y;
        if(Y >= X && n - m >= Y - X) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    

    return 0;
}