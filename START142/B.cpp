#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

bool solve(){
    int x, y;
    cin >> x >> y;
    if(x + 2 == y + 1) return true;
    if(x + 1 == y + 1) return true;
    if(x + 0 == y + 1) return true;
    if(x + 2 == y + 0) return true;
    if(x + 1 == y + 0) return true;
    if(x + 0 == y + 0) return true;
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