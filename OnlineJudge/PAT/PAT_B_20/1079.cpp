//延迟的回文数
#include<iostream>
using namespace std;
void reverse1(string &a){
    for(int i=0;i<a.length()/2;i++){
        char temp;
        temp=a[i];
        a[i]=a[a.length()-1-i];
        a[a.length()-1-i]=temp;
    }
}
int main(){
    string a;
    cin>>a;
    string b=a;
    //reverse(b.begin(),b.end());
    reverse1(b);
    //cout<<b;return 0;
    int k=10;
    //if(a==b) cout<<11245;return 0;
    while(a!=b&&k!=0){
        k--;
        string ch;
        int t=0;
        cout<<a<<" + "<<b<<" = ";
        for(int i=b.length()-1;i>=0;i--){
            int p=(a[i]-'0')+(b[i]-'0')+t;
            if(p>=10) {p=p-10;t=1;}
            else t=0;
            ch+=p+'0';

        }
        if(t==1) ch+=t+'0';
        a=ch;
        b=ch;
        //reverse(a.begin(),a.end());
        reverse1(a);
        cout<<a<<endl;
    }
    if(a==b) cout<<a<<" is a palindromic number."<<endl;
    else cout<<"Not found in 10 iterations."<<endl;
    return 0;
}
