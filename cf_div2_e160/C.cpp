#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
int f[35];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;

    auto check = [&](int x) -> bool {
        int t = 0;
        for(int i = 0; i < 30; i ++ ){
            t += f[i];
            if((x >> i) & 1){
                if(t == 0) return false;
                t --;
            }
            t >>= 1;
        }
        return true;
    };

    for(int tt = 0; tt < m; tt ++ ){
        int op, x;
        cin >> op >> x;
        if(op == 1){
            f[x] ++ ;
        } else {
            if(check(x)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    

    return 0;
}