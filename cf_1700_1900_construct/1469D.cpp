/*
分割递归
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void divd(int l, int r){
    if(r <= 2) return ;
    int mid = ceil(sqrt(r));
    for(int i = mid + 1; i < r; i ++ ){
        cout << i << " " << r << endl;
    }
    cout << r << " " << mid << endl;
    cout << r << " " << mid << endl;
    divd(l, mid);
}

void solve(){
    int n;
    cin >> n;
    int x = n;
    int op = 0;
    while(x > 2){
        x = ceil(sqrt(x));
        op ++ ;
    }
    
    cout << n - 2 + op << endl;
    divd(1, n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}