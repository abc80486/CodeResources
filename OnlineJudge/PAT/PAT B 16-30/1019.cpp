
/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<time.h>
//#include<window>
//#include<math.h>
//int t1,t2;
using namespace std;
int main(){
    //t1=clock();
    int ch=0;
    char a[5];
    scanf("%s",a);
    char maxx[5],minn[5];
    if(a[0]==a[1]&&a[2]==a[3]&&a[1]==a[2]){
         printf("%s - %s = 0000\n",a,a);
         return 0;}
    int n=100;
    while(ch!=6174&&n--!=0){
        int u,v;
        for(int i=0;i<5;i++){
            maxx[i]=a[i];minn[i]=a[i];
        }
        sort(minn,minn+4);sort(maxx,maxx+4,greater<int>());
        u=atoi(maxx);v=atoi(minn);
        ch=u-v;
        if(n!=99) printf("\n");
        printf("%04d - %04d = %04d",u,v,ch);
        sprintf(a,"%04d",ch);
        //a[4]='\0';
        
    }
    //t2=clock();
    //cout<<(t2-t1)/CLOCKS_PER_SEC<<endl;
    return 0;
}*/
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,maxx,minn, a[4];
    scanf("%d",&n);
    a[0]=n/1000;
    a[1]=n%1000/100;
    a[2]=n%100/10;
    a[3]=n%10;
    if(a[0]==a[1]&&a[3]==a[2]&&a[1]==a[3]){
        printf("%04d - %04d = 0000\n",n,n);return 0;
    }
    int k=100;
    do{
    if(k--==0) break;
    a[0]=n/1000;
    a[1]=n%1000/100;
    a[2]=n%100/10;
    a[3]=n%10;
    sort(a,a+4);
    minn=a[0]*1000+a[1]*100+a[2]*10+a[3];
    maxx=a[3]*1000+a[2]*100+a[1]*10+a[0];
    printf("%04d - %04d = %04d\n",maxx,minn,maxx-minn);
    n=maxx-minn;}
    while(n!=6174);
    return 0;
}