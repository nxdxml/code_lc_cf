#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

bool check(int a, int b){
    if((a & 1) && (b & 1)) return false;
    if((a == b * 2) && (b & 1)) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        if(check(a, b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    

    return 0;
}