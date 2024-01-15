#include<bits/stdc++.h>
#define endl '\n'
#define pair<int, int > PII
using namespace std;

int beautifulSubstrings(string s, int k) {
    int n = s.size();
    int cnt = 0;
    for(int i = 0; i < n; i ++ ){
        int delta = 0;
        for(int j = i; j < n; j ++ ){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') delta ++;
            else delta --;
            if(!delta && (((j - i + 1 >> 1) * (j - i + 1 >> 1) % k) == 0)) {
                // cout << i << " " << j << endl;
                cnt ++;}
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    int k;
    cin >> s >> k;
    // cout << s << " " << k << endl;
    cout << beautifulSubstrings(s, k) << endl;    

    return 0;
}