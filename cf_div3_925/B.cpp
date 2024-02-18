#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
LL a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T -- ){
        int n; cin >> n;
        LL sum = 0;
        for(int i = 0; i < n; i ++ ) {
            cin >> a[i];
            sum += a[i];
        }
        LL avg = sum / n;
        // cout << "avg = " << avg << endl;
        LL t = 0;
        bool fg = 1;
        for(int i = 0; i < n; i ++ ){
            if(t + a[i] < avg){
                cout << "No" << endl;
                fg = 0;
                break;
            }
            t += a[i] - avg;
        }
        if(fg) cout << "Yes" << endl;

    }

    return 0;
}