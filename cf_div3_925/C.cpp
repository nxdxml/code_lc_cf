#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int n; cin >> n;
        for(int i = 0; i < n; i ++ ){
            cin >> a[i];
        }
        int t1 = -1;
        for(int i = 1; i < n; i ++ ){
            if(a[i] != a[i - 1]){
                t1 = i;
                break;
            }
        }
        if(t1 == -1) {
            cout << 0 << endl;
            continue;
        }
        int t2;
        for(int i = n - 2; i >= 0; i -- ){
            if(a[i] != a[i + 1]){
                t2 = i;
                break;
            }
        }
        if(a[0] == a[n - 1]) cout << t2 - t1 + 1 << endl;
        else cout << min(n - 1 - t1 + 1, t2 - 0 + 1) << endl;
    }
    

    return 0;
}