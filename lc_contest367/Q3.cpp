
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

const int N = 1e5 + 5;
int f[N][4];
vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    int n = nums.size();
    f[0][0] = f[0][1] = nums[0];
    f[n - 1][2] = f[n - 1][3] = nums[n - 1];
    for(int i = 1; i < n; i ++ ){
        f[i][0] = min(f[i - 1][0], nums[i]);
        f[i][1] = max(f[i - 1][1], nums[i]);
    }
    for(int i = n - 2; i >= 0; i -- ){
        f[i][2] = min(f[i + 1][2], nums[i]);
        f[i][3] = max(f[i + 1][3], nums[i]);
    }
    vector<int> ans;
    for(int i = 0; i < n; i ++ ){
        // 0, i - iDiff
        // i + iDiff, n - 1
        int delta = INT_MIN;
        if(i - indexDifference >= 0){
            delta = max(max(abs(f[i - indexDifference][0] - nums[i]), abs(f[i - indexDifference][1] - nums[i])), delta);
        }
        if(i + indexDifference <= n - 1){
            delta = max(max(abs(f[i + indexDifference][2] - nums[i]), abs(f[i + indexDifference][3] - nums[i])), delta);
        }
        if(delta >= valueDifference){
            for(int j = 0; j < n; j ++ ){
                if(abs(j - i) >= indexDifference && abs(nums[j] - nums[i]) >= valueDifference) {
                    return vector<int>{i, j};
                }
            }
        }
    }
    return vector<int>{-1, -1};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, iDiff, vDiff;
    cin >> n >> iDiff >> vDiff;
    vector<int> nums(n, 0);
    
    for(int i = 0; i < n; i ++ ) cin >> nums[i];

    auto ans = findIndices(nums, iDiff, vDiff);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}