#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e5 + 5;
struct node {
    int a, b;
}f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        int a, b;
        cin >> a >> b;
        f[i] = {a, b};
    }
    sort(f, f + n, [](auto& t1, auto &t2) {
        if(t1.a != t2.a){
            return t1.a > t2.a;
        }
        return t1.b < t2.b;
    });
    int ans = 1;
    for(int i = 1; i < n; i ++ ){
        if(f[i].a != f[i - 1].a || f[i].b != f[i - 1].b) ans ++;

    }
    cout << ans << endl;

    return 0;
}