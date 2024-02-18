#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        int n;
        cin >> n;
        int t = 0;
        for(int i = 1; i <= n; i ++ ){
            // x * k > t
            int x;
            cin >> x;
            int k = t / x + 1;
            t = k * x;
        }
        cout << t << endl;
    }

    return 0;
}