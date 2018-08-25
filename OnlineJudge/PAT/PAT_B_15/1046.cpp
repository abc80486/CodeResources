//字符处理；
#include<iostream>
int main(){
    int a=0,b=0;
    int n;
    scanf("%d",&n);
    while(n--){
        int a1,a2,b1,b2;
        scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
        if(a2==a1+b1&&b2!=a2) b++;
        if(b2==a1+b1&&a2!=b2) a++;
    }
    printf("%d %d\n",a,b);
    return 0;
}