#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        int n;
        string a, b;
        cin >> n >> a >> b;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i ++ ){
            if(a[i] == '0' && b[i] == '1') cnt1 ++ ;
            if(a[i] == '1' && b[i] == '0') cnt2 ++ ;
        }
        cout << max(cnt1, cnt2) << endl;
    }

    return 0;
}