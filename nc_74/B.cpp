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
        int x, y;
        cin >> x >> y;
        if(y % x) cout << "-1" << endl;
        else cout << x << " " << y << endl;
    }
    

    return 0;
}