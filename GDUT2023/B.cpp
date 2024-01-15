#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
int n, m;
const int N = 1e5 + 5;
struct node{
    int cnt;
    bool isAC;
}p[N];
int acCnt, pCnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        p[i].cnt = 0;
        p[i].isAC = false;
    }
    for(int i = 0; i < m; i ++ ){
        int x; string s;
        cin >> x >> s;
        if(s == "AC"){
            if(p[x].isAC == false){
                acCnt ++;
                pCnt += p[x].cnt;
                p[x].isAC = true;  
            }
        } else if(!p[x].isAC) {
            p[x].cnt ++ ;
        }
    }
    cout << acCnt << " " << pCnt << endl;
    return 0;
}