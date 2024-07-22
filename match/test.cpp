/*
正则表达式匹配问题：假定正则表达式中只有如下字母存在：英文字母（区分大小写）、 数字、通配符“?”和“*”。其中，“?”代表一个未知的字符，通配符“*”代表0或N个未知的字符。在某目录下的文件中寻找一个正则表达式，要求能匹配最多的文件且不能匹配任何一个不要操作的文件，在此前提下寻求长度最短的正则表达式，如果有不止一个结果则输出其中任意一个。
如：输入为EXCHANGE+, EXTRA+,HARDWARE+, MOUSE-,NETWORK-（其中+表示选中，-表示不选），则所求表达式为*A*，最多匹配个数为3。
做相关实验分析算法特性。输入文件名不超过300，每个文件名不超过8个字符的，考虑文件选中和不选中的各种比率，须包含接近各占一半时的情形。
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // n <= 300, len(s) <= 8
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    // x x* *x *x*
    // 123 abc 456

    return 0;
}