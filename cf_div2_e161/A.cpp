#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

bool solve(){
    int n;;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < n; i ++ ){
        if(c[i] != a[i] && c[i] != b[i]) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) {
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    

    return 0;
}