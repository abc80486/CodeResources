#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;//输入
    string s = to_string(a + b);//数值转换为字符串
    int len = s.length();//获取字符串长度
    for (int i = 0; i < len; i++)//遍历
    {
        cout << s[i];//输出
        if (s[i] == '-')
            continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1)
            cout << ",";//从右向左每 三个字符分隔
    }
    return 0;
}