/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

bool solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n ; i ++ ) cin >> a[i];
    int last = -1, pos = -1;
    for(int i = 0; i < n - 1; i ++ ){
        int x = __gcd(a[i], a[i + 1]);
        if(x < last){
            pos = i;
            break;
        }
        last = x;
    }

    // 原来就行，删除最后一个
    if(pos == -1){
        return true;
    }


    auto check = [&](vector<int>& b){
        int m = b.size();
        int last = -1;
        for(int i = 0; i < m - 1; i ++ ){
            int x = __gcd(b[i], b[i + 1]);
            if(x < last){
                return false;
            }
            last = x;
        }
        return true;
    };

    vector<int> b0 = a;
    vector<int> b1 = a;
    vector<int> b2 = a;
    if(pos - 1 >= 0) b0.erase(b0.begin() + pos - 1);
    b1.erase(b1.begin() + pos);
    if(pos + 1 < n) b2.erase(b2.begin() + pos + 1);
    return check(b0) || check(b1) || check(b2);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) {
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}