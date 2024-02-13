#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    n <<= 1;
    int t1 = 0, t2 = 0;
    int m1 = 0, m2 = 1;
    for(int i = 0; i < n; i ++ ){
        int x;
        cin >> x;
        t1 += m1 ^ x; m1 = !m1;
        t2 += m2 ^ x; m2 = !m2;
    }
    cout << min(t1 / 2, t2 / 2) << endl;
    

    return 0;
}