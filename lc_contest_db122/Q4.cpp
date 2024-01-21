#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

struct Magic {
    int K;
    multiset<LL> st1, st2;
    // st1中元素的和
    LL sum;

    Magic(int K) : K(K), sum(0) {}

    void adj(){
        // 尽量填补st1
        while(st1.size() < K && st2.size() > 0){
            LL t = *(st2.begin());
            st1.insert(t);
            sum += t;
            st2.erase(st2.begin());
        }
        // 不超过K
        while(st1.size() > K){
            LL t = *prev(st1.end());
            st2.insert(t);
            st1.erase(prev(st1.end()));
            sum -= t;
        }
    }

    void add(LL x){
        // st2不空就插入st2
        if(!st2.empty() && x >= *(st2.begin())) st2.insert(x);
        else st1.insert(x), sum += x;
        adj();  
    }

    void del(LL x){
        auto it = st1.find(x);
        // 不在1一定在2
        if(it != st1.end()) st1.erase(it), sum -= x;
        else st2.erase(st2.find(x));
        adj();
    }
};

long long minimumCost(vector<int>& a, int k, int dist) {
    // 前k小值
    int n = a.size();
    Magic mg(k - 2);
    for(int i = 1; i < k - 1; i ++ ) mg.add(a[i]);
    LL ans = mg.sum + a[k - 1];
    // 最后一个数字
    for(int i = k; i < n; i ++ ){
        int t = i - dist - 1;
        if(t > 0) mg.del(a[t]);;
        mg.add(a[i - 1]);
        ans = min(ans, mg.sum + a[i]);
    }

    return ans + a[0];

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, dist;
    cin >> n >> k >> dist;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    
    cout << minimumCost(a, k, dist) << endl;
    
    return 0;
}