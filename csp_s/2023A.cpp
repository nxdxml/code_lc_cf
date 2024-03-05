/*
    模拟统计
    n <= 8 决定了可以随便暴力
    转动相当于取模操作，用数字取模比较偏方便
    统计把状态转化成字符串
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    map<string, int> m;
    for(int i = 0; i < n; i ++ ){
        string t, p;
        for(int j = 0; j < 5; j ++ ) {
            cin >> p;
            t = t + p;
        }
        // 单独转
        for(int j = 0; j < 5; j ++ ){
            for(int k = 1; k < 10; k ++ ){
                int x = t[j] - '0';
                x = (x + k) % 10;
                p = t;
                p[j] = x + '0';
                m[p] ++ ;
            }
        }
        // 两个一起转
        for(int j = 0; j < 4; j ++ ){
            for(int k = 1; k < 10; k ++ ){
                int x = t[j] - '0';
                int y = t[j + 1] - '0';
                x = (x + k) % 10;
                y = (y + k) % 10;
                p = t;
                p[j] = x + '0';
                p[j + 1] = y + '0';
                m[p] ++ ;
            }
        }
    }
    int ans = 0;
    for(auto&& it : m){
        // n个状态都能更新过来
        if(it.second == n) ans ++ ;
    }
    cout << ans << endl;

    return 0;
}