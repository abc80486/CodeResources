//在霍格沃茨找零钱
#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    int m,n,t;
    scanf("%d.%d.%d",&a,&b,&c);
    scanf("%d.%d.%d",&m,&n,&t);
    int flag;
    if(a>m||(a==m&&b>n)||(a==m&&b==n&&c>t)){
        flag=0;
    }
    else flag=1;
    if(flag==0){
        int ch;
        ch=m;m=a;a=ch;
        ch=n;n=b;b=ch;
        ch=t;t=c;c=ch;
    }
    if(t>=c) t=t-c;
    else {
        n--;t=t+29-c;
    }
    if(n>=b) n=n-b;
    else{
        m--;n=n+17-b;
    }
    m=m-a;
    if(flag==0) cout<<"-";
    cout<<m<<"."<<n<<"."<<t<<endl;
    return 0;
}