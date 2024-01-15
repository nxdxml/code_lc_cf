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
    double C_16_12 = 16.0 * 15 * 14 * 13 / (1.0 * 2 * 3 * 4);

    while(T -- ){
        double ans = 0.0;
        double a, b, c;
        cin >> a >> b >> c;
        double t1 = (double)a / 16.0;
        double t2 = 1.0;
        double t3 = (double)b / 16.0;
        double t4 = 1.0;
        double t5 = (double)c / 16.0;
        double t6 = 1.0;
        double t7 = 1.0;
        for(int i = 0; i < 16; i ++ ) t2 *= t1;
        for(int i = 0; i < 4; i ++ ) t4 *= t3;
        for(int i = 0; i < 4; i ++ ) t6 *= t5;
        for(int i = 0; i < 12; i ++ ) t7 *= t1;
        // cout << t2 << " " << t4 << endl;
        ans += t2;
        ans += C_16_12 * t7 * t4;
        ans += C_16_12 * t7 * t6;
        // cout << ans << endl;
        printf("%.10lf\n", ans);

    }
    

    return 0;
}