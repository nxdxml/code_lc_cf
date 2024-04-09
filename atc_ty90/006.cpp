/*
求出字典序最小的定长子串1e5
难度5星

预处理贪心
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    string s;
    cin >> n >> m >> s;

    // f[i][c] 第i个位置后最近的字符c的位置

    vector<vector<int>> f(n, vector<int>(26, n));
    for(int i = n - 1; i >= 0; i -- ){
        if(i != n - 1)f[i] = f[i + 1];
        f[i][s[i] - 'a'] = i;
    }
    string res = "";
    int t = -1;
    for(int i = 0; i < m; i ++ ){
        for(int j = 0; j < 26; j ++ ){
            int k = f[t + 1][j];
            // 把这个和后面所有的字符都填上一定要足够，贪心填充
            if(n - k >= m - i){
                res += char(j + 'a');
                // move
                t = k;
                break; 
            }
        }
    }
    cout << res << endl;
    return 0;
}