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
        //cout<<a<<endl;
        if(a%5==0){if(a%2==0) a1+=a;}
        else if(a%5==1){
            p=0;
            if(t==0){a2+=a;t=1;}
            else{a2-=a;t=0;}
        }
        else if(a%5==2){
            a3++;
        }
        else if(a%5==3){
            q=0;
            k++;
            a4+=a;
        }
        else{
            if(a>a5) a5=a;
        }
        if(getchar()==10) break;
    }

    a4=a4/k;
    //cout<<a4;
    if(a1==0) cout<<"N";
    else cout<<a1;
    if(p==1) cout<<" N";
    else cout<<" "<<a2;
    if(a3==0) cout<<" N";
    else cout<<" "<<a3;
    //cout<<a1<<" "<<a2<<" "<<a3;
    if(q==1) cout<<" N";
    else printf(" %.1f",a4);
    if(a5==0) cout<<" N";
    else cout<<" "<<a5;
    return 0;
}