#include<cstdio>
int main(){
    int m,n,t=1;
    while(scanf("%d %d",&m,&n)!=EOF){
        if(n!=0){
            if(t==1) {printf("%d %d",m*n,n-1);
            t=0;}
            else printf(" %d %d",m*n,n-1);
        }
        
    }
    
    return 0;
}