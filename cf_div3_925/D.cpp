#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        map<PII, int> m;
        int n, x, y;
        LL ans = 0;
        cin >> n >> x >> y;
        for(int i = 0; i < n; i ++ ){
            cin >> a[i];
            int t1 = a[i] % x, t2 = a[i] % y;
            // cout << i << " " << t1 << " " << t2 << endl;
            PII p;
            p.first = (x - t1) % x, p.second = t2;
            if(m.count(p)) ans += m[p];

            m[{t1, t2}] ++;
        }
        cout << ans << endl;
    }
    

    return 0;
}