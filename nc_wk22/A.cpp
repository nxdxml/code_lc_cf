#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    int cnt = 0;
    int j = 0;
    for(int i = 0; i < n; i ++ ){
        if(s.substr(i, 3) == "red"){
            cnt ++ ;
            i += 2;
        }
    }
    if(cnt >= 2) puts("Yes");
    else puts("No");
    

    return 0;
}