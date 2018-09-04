//宇宙无敌加法器
#include<iostream>
#include<string>
using namespace std;
int main() {
    string a, b, c;
    int l1, l2, l3, l, i;
    int p[22] = {0}, q[22] = {0}, r[22] = {0}, d[22];
    cin>>a>>b>>c;
    l1 = a.length();l2 = b.length();l3 = c.length();
    for (i=0; i<l1; i++)    p[i] = a[l1-1-i] - '0';
    for (i=0; i<l2; i++)    q[i] = b[l2-1-i] - '0';
    for (i=0; i<l3; i++)    r[i] = c[l3-1-i] - '0';
    l = l1 >= l2 ? l1 : l2;
    int sum, jia=0;
    for (i=0; i<=l; i++) {
        if (p[i] == 0)  p[i] = 10;
        sum = jia+ q[i] + r[i];
        d[i] = sum % p[i];
        jia = sum / p[i];
    }
    int flag=0;
    for (i=l; i>=0; i--) {
        if (flag == 0 && d[i] == 0) continue;
        else{ cout<<d[i];flag = 1;}
    }
    if(flag==0) cout<<"0";
    cout<<endl;
    return 0;
}
