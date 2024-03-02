#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
const int N = 105;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i ++ ) cin >> a[i], sum += a[i];
    if(sum % 2){
        cout << 0 << endl;
        return 0;
    }
    bitset<200005> s;
    s[0] = 1;
    for(auto&& x : a){
        s |= s << x;
    }
    if(s[sum >> 1] == 0) {
        cout << 0 << endl;
        return 0;
    }
    int t = 30, ans = 0;
    for(int i = 0; i < n; i ++ ){
        int x = a[i];
        if(__builtin_ctz(x) < t){
            t = __builtin_ctz(x);
            ans = i;
        }
    }
    cout << 1 << endl << ans + 1 << endl;

    

    

    return 0;
}