#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N],b[N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n+m;i++){
		cin>>a[i];
		if(i<n) b[a[i]]=1;
	}
	sort(a,a+n+m);
	for(int i=0;i<n+m;i++){
        if(b[a[i]] && b[a[i+1]]) {
            cout<<"Yes\n";
            return 0;
        }
	}
	cout<<"No\n";
	return 0;
}