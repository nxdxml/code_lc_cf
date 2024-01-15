#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// const int N = 1e5 + 5;
const int N = 105;
int a[N], b[N];
int n, m, x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> x;
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    for(int i = 0; i < m; i ++ ){
        cin >> b[i];
    }
    sort(a, a + n, [](auto t1, auto t2){return t1 > t2;});
    sort(b, b + m, [](auto t1, auto t2){return t1 > t2;});
    
    int cnt = 0;
    int i = 0, j = 0;
    while(x >= 1){
        cnt ++;
        if(x - b[j] < 1) break;
        if(a[i] > 1 && i < n) {
            cnt ++;
            b[j] *= a[i];
            i ++;
        }
        x -= b[j ++];
        if(x < 1)break;
        if(j >= m){
            cout << -1 << endl;
            return 0;
        }
        
    }
    cout << cnt << endl;

    return 0;
}