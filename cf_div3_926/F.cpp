#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
struct node{
    int a, b;
}f[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i ++ ) {
            cin >> f[i].a >> f[i].b;
        }
        sort(f, f + m, [](auto& t1, auto& t2){
            return t1.b < t2.b;
        });
        int t = f[0].b;
        int cnt = 1;
        for(int i = 1; i < m; i ++ ){
            if(f[i].a >= t) cnt ++, t = f[i].b;
        }

        cout << cnt << endl;
    }

    return 0;
}