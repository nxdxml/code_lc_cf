#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
int f[N];
int divd(int x){
    int ret = 0;
    while(x){
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i <= 2e5; i ++ ){
        f[i] = f[i - 1] + divd(i);
    }

    int T;
    cin >> T;
    while(T -- ){
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    

    return 0;
}