// 分组依据为组内数除去完全平方数剩下的数字相等
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// n <= 1e4
long long maximumSum(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;
    for(int i = 1; i <= n; i ++ ){
        long long sum = 0;
        for(int j = 1; i * j * j <= n; j ++ ){
            sum += nums[-1 + i * j * j];
        }
        ans = max(ans, sum);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i ++ ) cin >> nums[i];
    cout << maximumSum(nums) << endl;
        

    return 0;
}