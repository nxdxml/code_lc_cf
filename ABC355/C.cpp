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
    int n, m;
    cin >> n >> m;
    vector<int> row(n + 1, 0), col(n + 1, 0);
    int d1 = 0, d2 = 0;
    for(int i = 1; i <= m; i ++ ){
        int x;
        cin >> x;
        int r = (x + n - 1) / n;
        int c = (x + + n - 1) % n + 1;
        // cout << r << " " << c << endl;
        if(++row[r] == n) {
            cout << i << endl;
            return 0;
        }
        if(++col[c] == n) {
            cout << i << endl;
            return 0;
        }
        if(r == c){
            if(++d1 == n) {
                cout << i << endl;
                return 0;
            }
        }
        if(r + c == n + 1){
            if(++d2 == n) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}