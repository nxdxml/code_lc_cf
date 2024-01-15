

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

string shortestBeautifulSubstring(string s, int k) {
    int n = s.size();
    vector<int> temp;
    for(int i = 0; i < n; i ++ ){
        if(s[i] == '1') temp.push_back(i);
    }
    int m = temp.size();
    if(m < k) return "";
    int cnt = INT_MAX;
    string ans;
    for(int i = 0, j = k - 1; j < m; i ++ , j ++ ){
        if(temp[j] - temp[i] < cnt) cnt = temp[j] - temp[i], ans = s.substr(temp[i], temp[j] - temp[i] + 1);
        else if(temp[j] - temp[i] == cnt && ans > s.substr(temp[i], temp[j] - temp[i] + 1)) ans = s.substr(temp[i], temp[j] - temp[i] + 1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int k;
    cin >> s >> k;
    cout << shortestBeautifulSubstring(s, k) << endl;
        

    return 0;
}