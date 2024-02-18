#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
// int a[N];
int len(int x){
    // int ret = 0;
    // while(x){
    //     x /= 10;
    //     ret ++ ;
    // }
    // return ret;
    return (int)floor(log10(x)) + 1;
}
int zero_cnt(int x){
    // if(x == 0) return 1;
    int ret = 0;
    while((x % 10) == 0){
        ret ++;
        x /= 10;
    }
    return ret;
}
int f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << (int)floor(log10(10)) + 1;
    int T;
    cin >> T;
    while(T -- ){
        int n, m;
        cin >> n >> m;
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < n; i ++ ){
            int x;
            cin >> x;
            int d = len(x);
            sum += d;
            int t = zero_cnt(x);

            if(t) f[cnt ++ ] = t;
        }

        sort(f, f + cnt);

        for(int i = cnt - 1; i >= 0; i -= 2 ){
            sum -= f[i];
            if(sum < m + 1) break;
        }

        if(sum >= m + 1) cout << "Sasha" << endl;
        else cout << "Anna" << endl;
    }
    

    return 0;
}