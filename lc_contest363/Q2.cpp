#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

int countWays(vector<int>& nums) {
    int n = nums.size();
    int ret = 0;
    sort(nums.begin(), nums.end());
    for(int i = 1; i < n; i ++ ){
        if(i > nums[i - 1] && i < nums[i]) ret ++ ;
    }
    if(0 < nums[0]) ret ++;
    if(n > nums[n - 1]) ret ++;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i ++ ) cin >> nums[i];
    cout << countWays(nums) << endl;
    

    return 0;
}