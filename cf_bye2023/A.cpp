#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;
int b[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int n, k;
        cin >> n >> k;
        int t = 1;
        for(int i = 0; i < n; i ++ ){
            cin >> b[i];
        }
        bool fg = 0;
        for(int i = 0; i < n; i ++ ){
            t *= b[i];
            if(t > 2023) {fg = 1; break; }
        }
        if(fg || (2023 % t != 0)) {cout << "NO" << endl; continue;}
        cout << "YES" << endl;
        cout << 2023 / t;
        k --;
        while( k -- ){
            cout << " 1"; 
        }
        cout << endl;
    }
    

    return 0;
}