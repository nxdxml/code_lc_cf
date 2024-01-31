#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
struct node{
    int a, b;
}f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    
    while(T -- ){
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++ ) cin >> f[i].a;
        for(int i = 0; i < n; i ++ ) cin >> f[i].b;

        sort(f, f + n, [](const auto& t1, const auto& t2){
            return t1.a + t1.b < t2.a + t2.b;
        });

        for(int i = 0; i < n; i ++ ) {
            cout << f[i].a << " ";
        } cout << endl;
        for(int i = 0; i < n; i ++ ) {
            cout << f[i].b << " ";
        } cout << endl;
    }
    

    return 0;
}