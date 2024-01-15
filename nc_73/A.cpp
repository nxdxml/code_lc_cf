#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
int n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d, e;
    int A, B, C, D;
    cin >> a >> b >> c >> d >> e;
    cin >> A >> B >> C >> D;
    int t = a * A + b * B + c * C - d * D;
    if(t > e)puts("YES");
    else puts("NO");



    return 0;
}