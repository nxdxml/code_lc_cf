#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

void solve(){
    LL x, y;
    cin >> x >> y;
    if(x == 2 || y == 2){
        cout << x * y / 4 * 6 << endl;
    } else {
        cout << x * y + 4 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}