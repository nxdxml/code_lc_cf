#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m = 1000;

    int ret = 0;
    for(int i = 1; i <= 1000; i ++ ){
        ret = max(m * i * (10000 / i), ret);
        
    }
    cout << ret << endl;
    
    

    return 0;
}