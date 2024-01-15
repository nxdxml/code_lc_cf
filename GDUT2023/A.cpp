#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
int T, x, y, z;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T -- ){
        cin >> x >> y >> z;
        int ans = 7;
        if((z + y + x) % 7) ans = (z + y + x) % 7;
        cout << ans << endl;
    }
    

    return 0;
}