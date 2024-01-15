#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
const int N = 1e5 + 5;
int f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++ ){
            cin >> f[i];
        }
        int a = 0, b = 0;
        ll sum = 0;
        for(int i = 0; i < n; i ++ ){
            sum += f[i];
            if(f[i] & 1) a ++ ;
            else b ++ ;
            int s = a / 3;
            int t = a % 3;
            if(i == 0) cout << sum << " ";
            else cout << sum - s - (t == 1) << " ";
        }
        cout << endl;
    }
    

    return 0;
}