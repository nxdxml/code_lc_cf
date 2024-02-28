#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e5 + 5;
int a[N];
bool solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + n);
    int t = a[0];
    if(a[0] != a[1]) return true;
    for(int i = 1; i < n; i ++ ){
        if(a[i] % a[0]) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T --){
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}