#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack<int> s;
    while(true){
        int x;
        cin >> x;
        s.push(x);
        if(x == 0) break;
    }
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    

    return 0;
}