#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

int removeAlmostEqualCharacters(string s) {
    int n = s.size();
    int j = 0, i;
    int cnt = 0;
    for(i = 1; i < n; i ++ ){
        if(abs(s[i] - s[i - 1]) > 1){
            cnt += (i - j) / 2;
            j = i;
        }

    }
    cnt += (i - j) / 2;
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    
    cout << removeAlmostEqualCharacters(s) << endl;

    return 0;
}