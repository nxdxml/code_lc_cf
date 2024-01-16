#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int solve(){
    int n, m, x1, x2, y1, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    // a在b下面
    if(x1 >= x2) return 2;

    int d = x2 - x1;
    
    if(d & 1){ // a可能赢
        if(y1 == y2) return 0;
        else if(y1 < y2){
            int t1 = min(d / 2 + 1 + y1, m);
            int t2 = min(d / 2 + y2, m);
            if(t1 == t2) return 0;
            else return 2;
        } else {
            int t1 = max(y1 - d / 2 - 1, 1);
            int t2 = max(y2 - d / 2, 1);
            if(t1 == t2) return 0;
            else return 2;
        }
    } else { // b
        if(y1 == y2) return 1;
        else if(y1 > y2){
            int t1 = min(d / 2 + 1 + y1, m);
            int t2 = min(d / 2 + y2, m);
            if(t1 == t2) return 1;
            else return 2;
        } else {
            int t1 = max(y1 - d / 2 - 1, 1);
            int t2 = max(y2 - d / 2, 1);
            if(t1 == t2) return 1;
            else return 2;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) {
        int x = solve();
        if(x == 0) cout << "Alice" << endl;
        else if(x == 1) cout << "Bob" << endl;
        else cout << "Draw" << endl;
    }
    

    return 0;
}