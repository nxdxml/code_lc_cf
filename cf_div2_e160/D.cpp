// 1 2 5 4 3 8 7 6
// * *     * * *
// 来源1不存在倒数第二个数字2小于当前数最大数到当前的所有数字3单调栈中数字
// f[i] 以 p[i]结尾的子串总数
// 答案为最后留在栈内的元素和
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
const int N = 3e5 + 5;
const int MOD = 998244353;
int T;
int f[N], p[N], preSum[N];
int solve(int n){
    for(int i = 1; i <= n; i ++ ){
        cin >> p[i];
        f[i] = 0;
    }
    stack<int> stk;
    int stk_sum = 0;
    int pre_sum = 0;
    for(int i = 1; i <= n; i ++ ){
        while(!stk.empty() && p[i] < p[stk.top()]) {
            stk_sum = (stk_sum - f[stk.top()]) % MOD;
            stk.pop();
        }
        // 1
        if(stk.empty()) f[i] ++ ;
        // 2
        int j = stk.empty() ? 0 : stk.top();
        f[i] = (f[i] + preSum[i - 1] - preSum[j]) % MOD;
        // 3
        f[i] = (f[i] + stk_sum) % MOD;

        

        preSum[i] = (preSum[i - 1] + f[i]) % MOD;
        stk_sum = (stk_sum + f[i]) % MOD;
        stk.push(i);
    }
    // for(int i = 1; i <= n; i ++ ){
    //     cout << i << " " << f[i] << endl;
    // }
    return (stk_sum + MOD) % MOD;

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T -- ){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    

    return 0;
}