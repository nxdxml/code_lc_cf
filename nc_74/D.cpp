#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)cin >> a[i];
        if (n == 1) {
            if (a[1] == 0 || a[1] & 1)cout << "Dog\n";
            else cout << "Cat\n";
        } else if (n == 2) {
            if (a[1] > a[2])swap(a[1], a[2]);
            if (a[2] == 0)cout << "Dog\n";
            else {
                if (a[2] == a[1] + 1) {
                    if (a[1] == 0)cout << "Dog\n";
                    else cout << "Cat\n";
                } else cout << "Dog\n";
            }
        } else {
            int i = (n - 1) / 2;
            int j = n - i;
            long long res = 0;
            int cnt0 = 0;
            for (int i = 1; i <= n; i++)res += a[i], cnt0 += (a[i] == 0);
            if (res == 0 || n - cnt0 <= cnt0)cout << "Dog\n";
            else {
                res -= j;
                if (res & 1)cout << "Cat\n";
                else cout << "Dog\n";
            }
        }
    }
}