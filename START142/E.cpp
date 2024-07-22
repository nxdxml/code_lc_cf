#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

bool isPrime(int x){
    if(x < 2) return 0;
    for(int i = 2; i * i <= x; i ++ ){
        if(x % i == 0) return 0;
    }
    return 1;
}

void solve(){
    int x;
    cin >> x;
    while(isPrime(x) != 1) x ++ ;
    LL y = x ++ ;
    while(isPrime(x) != 1) x ++ ;
    y *= x;
    cout << y << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        solve();
    }
    

    return 0;
}