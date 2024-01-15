#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int, int > PII;

long long beautifulSubstrings(string s, int k) {
    int n = s.size();
    long long ret = 0;
    //{i % k} sum
    map<PII, int > hashMap;

    // i * i % 4k == 0;
    auto deal_k = [&](int k) -> int {
        int res = 1;
        for(int i = 2; i <= k / i; i ++ ){
            if(k % i == 0){
                int sum = 0;
                while(k % i == 0){
                    k /= i;
                    sum ++;
                }
                res *= pow(i, sum + 1 >> 1);
                // res *= pow(i, sum + 1 >> 1);
            }
        }
        if(k > 1){
            res *= k;
        }
        return res;
    };

    int kk = deal_k(4 * k);
    // cout << kk << endl;
    hashMap[{-1 + kk, 0}] = 1;
    int sum = 0;
    for(int i = 0; i < n; i ++ ){
        int t = -1;
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') t = 1;
        sum += t;
        // cout << i << " " << sum << endl;
        ret += hashMap[{i % kk, sum}]++;
    }
    return ret;
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