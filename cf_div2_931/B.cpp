#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 50;
int f[30] = {
    0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1, 2, 3, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 4
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int T;
    cin >> T;
    while(T -- ){
        int x;
        cin >> x;
        int t = x / 15;
        int y  = x % 15;
        if(t > 0){
            t--;
            y += 15;
        }
        cout << t + f[y] << endl;
    }

    return 0;
}