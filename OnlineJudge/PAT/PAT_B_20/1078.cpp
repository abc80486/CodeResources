//字符串的压缩与解压
#include<iostream>
using namespace std;
int main(){
    char a;
    cin>>a;
    getchar();
    if(a=='C'){
        char ch;int s=1;
        char ou=getchar();
        while((ch=getchar())!=10){
            if(ch==ou)
                s++;
            else{
                if(s>1) cout<<s;
                cout<<ou;
                s=1;ou=ch;
            }
        }
        if(s>1) cout<<s;
        cout<<ou;
        cout<<endl;
    }
    if(a=='D'){
        int n;char ch;
        string t;
        while((ch=getchar())!=10){
            if(ch>='0'&&ch<='9'){
                t+=ch;
            }
            else{
                if(t.length()==0){
                    cout<<ch;
                }
                else{
                    for(int i=stoi(t);i>0;i--){
                        cout<<ch;
                    }
                }
                t.clear();
            }
        }
    }
    return 0;
}
/*
C
TTTTThhiiiis isssss a   tesssst CAaaa as
5T2h4is i5s a3 te4st CA3a as

D
5T2h4is i5s a3 te4st CA3a as10Z
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
*/