#include<iostream>
int main(){
    int m,n,a,b,t;
    scanf("%d %d %d %d %d",&m,&n,&a,&b,&t);
    for(int i=0;i<m;i++){
        int p=0;
        for(int j=0;j<n;j++){
            int ch;
            scanf("%d",&ch);
            if(ch>=a&&ch<=b) {
                if(p!=0) printf(" ");
                printf("%03d",t);p=1;}
            else {
                if(p!=0) printf(" ");
                printf("%03d",ch);p=1;
            }
        }
        printf("\n");
    }
    return 0;
}