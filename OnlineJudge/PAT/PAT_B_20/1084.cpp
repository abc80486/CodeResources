//1084外观数列；
#include<iostream>
//#include<string>
using namespace std;
int main(){
    string a,b;
    int n;
    cin>>a>>n;
    int ch,s;
    while(--n){
        string b;char ch;
        ch=a[0],s=0;
    for(int i=0;i<a.length();i++){
       if(a[i]==ch) 
           s++;
        else{
            b+=ch;
            b+=s+'0';
            ch=a[i];
            s=1;
        }
    }
    if(s>0){
        b+=ch;
        b+=s+'0';
    }
     a=b;
    }
    cout<<a<<endl;
    return 0;
}
