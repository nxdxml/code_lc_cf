// 相邻字母相差至多为2 -> 多个子串分别处理, 得到子串长度len，子串子母个数m
// 每个字母出现次数均为k -> m * k == len
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

int countCompleteSubstrings(string word, int k) {
    auto dealSub = [&](string s) -> int {
        int n = s.size();
        int ret = 0;
        for(int i = 1; i <= 26 && i * k <= n; i ++ ){
            int len = i * k;
            int cnt[26]{};
            auto check = [&] {
                for(int i = 0; i < 26; i ++ ){
                    if(cnt[i] && cnt[i] != k) return;
                }
                ret ++ ;
            };
            for(int j = 0; j < n; j ++ ){
                cnt[s[j] - 'a'] ++ ;
                int l = j - len + 1;
                if(l >= 0){
                    check();
                    cnt[s[l] - 'a'] --;
                }
            }
        }
        return ret;
    };
    int j = 0, i;
    int ans = 0;
    for(i = 1; i < word.size(); i ++ ){
        if(abs(word[i] - word[i - 1]) > 2){
            ans += dealSub(word.substr(j, i - j));
            j = i;
        }
    }
    ans += dealSub(word.substr(j, i - j));
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string word;
    int k;
    cin >> word >> k;
    cout << countCompleteSubstrings(word, k) << endl;
    

    return 0;
}