#include<iostream>
#include<math.h>
int main(){
    double r1,p1,r2,p2;
    scanf("%lf %lf %lf %lf",&r1,&p1,&r2,&p2);
    double r=r1*r2*cos(p1+p2);
    double p=r1*r2*sin(p1+p2);
    if(r>-0.005&&r<0) printf("0.00");
    else printf("%.2lf",r);
    if(p>-0.005&&p<=0) printf("+0.00i");
    else if(p>0) printf("+%.2lfi",p);
    else printf("%.2lfi",p);
    
    return 0;
}