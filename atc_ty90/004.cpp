/*
返回同行列所有元素和
难度2星
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2005;
int a[N][N];
int r[N], c[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            cin >> a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            cout << r[i] + c[j] - a[i][j] << " "; 
        }
        cout << endl;
    }


    return 0;
}