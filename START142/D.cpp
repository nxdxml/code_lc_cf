#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e5 + 5;
LL a[N];
void solve(){
    int n;
    cin >> n;
    LL x = 0;
    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
        x |= a[i];
    }
    LL t = 1;
    while((t | x) == x){
        t *= 2;
    }
    int res = 0;
    for(int i = 0; i < n; i ++ ){
        if(a[i] >= t * 2) res ++ ;
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}