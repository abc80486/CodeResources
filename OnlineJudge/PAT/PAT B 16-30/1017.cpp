#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
    char a[1003];
    int n,b=0;
    scanf("%s%d",a,&n);
    for(int i=0;a[i]!='\0';i++){
        int k=(int(a[i]-'0')+b*10)/n;
        if(i>=1){
            cout<<k;
        }
        else if(k>=1) cout<<k;
        else if(a[1]=='\0'){cout<<"0";}
        else ;
        b=(int(a[i]-'0')+b*10)%n;
    }
    cout<<" "<<b;
    return 0;
}