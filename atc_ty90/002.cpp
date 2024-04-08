/*
按字典序输出所有长度为n的括号序列
1 <= n <= 20
难度3星

模拟
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
    int n;
    cin >> n;
    if(n & 1) return 0;
    for(int i = 0; i < 1 << n; i ++ ){
        string s = "";
        for(int j = n - 1; j >= 0; j -- ){
            if(i >> j & 1) s = s + ')';
            else s = s + '(';
        }
        auto ck = [&](){
            int t = 0;
            for(int i = 0; i < n; i ++ ){
                if(s[i] == '(') t ++ ;
                else t --;
                if(t < 0) return false;
            }
            return t == 0;
        };
        if(ck()) cout << s << endl;
    }
    

    return 0;
}