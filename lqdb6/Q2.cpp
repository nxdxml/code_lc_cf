#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
int a[N], b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i], a[i] *= 2;
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    
    sort(a, a + n); 
    sort(b, b + n);
    int ans = 0;
    int j = n - 1, i = n - 1;
    for( ; j >= 0; j -- ){
        if(a[i] > b[j]){
            i -- ;
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}