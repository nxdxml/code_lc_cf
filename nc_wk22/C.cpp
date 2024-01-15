#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

long long n, k, x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> x;

    if(n > k){
        cout << -1 << endl;
        return 0;
    }

    long long min_sum = (1 + n) * n / 2;
    long long max_sum;
    if(n & 1){
        max_sum = (k - n + 1 + k) / 2 * n;
    } else {
        max_sum = (k - n + 1 + k) * (n / 2);
    }

    // cout << min_sum << " " << max_sum << endl;

    if(x < min_sum || x > max_sum) {
        cout << -1 << endl;
        return 0;
    }
    long long delta = k - n;
    if(delta == 0){
        for(int i = 1; i <= n; i ++ ){
            cout << i << " ";
        }
        return 0;
    }
    long long t1 = x - min_sum;
    long long t2 = t1 / delta;
    long long t3 = t1 % delta;

    for(long long i = 1; i <= n; i ++ ){
        if(i <= n - t2 - 1) cout << i << " ";
        else if(i == n - t2) cout << i + t3 << " ";
        else cout << i + delta << " ";
    }
    cout << endl;

    

    return 0;
}