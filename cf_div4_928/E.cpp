#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;

int find(int n, int k, int dep){
    int sep = (n + 1) / 2;
    if(k <= sep) return dep * (2 * k - 1);
    return find(n - sep, k - sep, dep * 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        int n, k;
        cin >> n >> k;
        cout << find(n, k, 1) << endl;
    }

    return 0;
}