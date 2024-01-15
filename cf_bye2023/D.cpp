#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<string>> ans(105);
    ans[1].push_back("1");

    ans[3].push_back("169");
    ans[3].push_back("961");
    ans[3].push_back("196");
    string zero = "";
    for(int i = 5; i <= 99; i += 2){
        for(auto s : ans[i - 2]){
            ans[i].push_back(s + "00");
        }
        zero = zero + "0";
        ans[i].push_back("1" + zero + "6" + zero + "9");
        ans[i].push_back("9" + zero + "6" + zero + "1");
    }
    int T;
    cin >> T;
    while (T -- )
    {
        int n;
        cin >> n;
        for(auto s : ans[n]){
            cout << s << endl;
        }
    }
    
    
// 1
// 169 192 961
// 10609 90601 16900 19200 96100
// 1006009 9006001 1690000 1920000 9610000 1060900 9060100
    return 0;
}