#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int t = -1;
    for(int i = 0; i < s.size(); i ++ ){
        if(s[i] == '.') t = i;
    }
    cout << s.substr(t + 1) << endl;
    

    return 0;
}