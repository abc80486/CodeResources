#include<cstdio>
//sing namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        //printf("%d\n",n);
        char a[3];
        for(int i=0;i<4;i++){
            scanf("%s",a);
            //cin>>a;
            if(a[2]=='T'){
                
                if(a[0]=='A') printf("1");
                else if(a[0]=='B') printf("2");
                else if(a[0]=='C') printf("3");
                else printf("4");
                //break;
            }
            //else ;
        }
        
    }
    printf("\n");
    return 0;
}