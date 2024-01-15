#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int n;
        string a, b;
        cin >> n >> a >> b;
        vector<int> ans;

        
        int t = a[0] - '0';
        for(int i = 0; i < n - 1; i ++ ){
            if(t != (a[i + 1] - '0')) t ^= 1, ans.push_back(i + 1); 
        }
        if(t) ans.push_back(n);

        stack<int> stk;
        t = b[0] - '0';
        for(int i = 0; i < n - 1; i ++ ){
            if(t != (b[i + 1] - '0')) t ^= 1, stk.push(i + 1); 
        }
        if(t) stk.push(n);

        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }

        cout << ans.size();
        for(auto x : ans){
            cout << " " << x;
        }
        cout << endl;
    }
    

    return 0;
}