#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int a,n;
    int a1=0,a2=0,a3=0,a5=0,t=0,k=0,p=1,q=1;
    float a4=0;
    cin>>n;
    while(n--){
        cin>>a;
        switch(a%5){
            case 0:if(a%2==0) a1+=a;break;
            case 1: p=0;
                    if(t==0){
                            a2+=a;t=1;}
                    else{
                            a2-=a;t=0;}
                    break;
            case 2: a3++;  break;
            case 3: q=0;
                    k++;
                    a4+=a;break;
            default: if(a>a5) a5=a;
        }
        if(getchar()==10) break;
    }
    a4=a4/k;
    if(a1==0) cout<<"N";
    else cout<<a1;
    if(p==1) cout<<" N";
    else cout<<" "<<a2;
    if(a3==0) cout<<" N";
    else cout<<" "<<a3;
    if(q==1) cout<<" N";
    else printf(" %.1f",a4);
    if(a5==0) cout<<" N";
    else cout<<" "<<a5;
    return 0;
}