#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
int T;
long long n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T -- ){
        cin >> n;
        if(n == 1) cout << 9 << endl;
        else cout << 5 << endl;
    }
    

    return 0;
}