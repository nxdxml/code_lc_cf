#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int k, m;
        cin >> k >> m;
        auto check = [&](int x) -> bool {
            double t = (double)x;
            return sqrt(t) + floor(log2(t) / log2(k)) - m > 0;
        };
        int l = 1, r = 1e9;
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }

    return 0;
}