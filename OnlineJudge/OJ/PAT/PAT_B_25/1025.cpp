#include<iostream>
using namespace std;
struct stu{
    int value;
    int next;
};
int main(){
    stu list[100005];
    int firstadd,n,l;
    scanf("%d%d%d",&firstadd,&n,&l);
     int first[n][2], end[n][2];
    while(n--){
        int ch;
        scanf("%d",&ch);
        scanf("%d%d",&list[ch].value,&list[ch].next);
    }
    //cout<<n;return 0;
    int k=0;
    while(firstadd!=-1){
        first[k][1]=firstadd;
        first[k++][0]=list[firstadd].value;
        firstadd=list[firstadd].next;
    }
    n=k;
    
    int t;
    for(int i=0;i<n;i++) {
        
        if(i>=(n-n%l)) {
            end[i][0]=first[i][0];
             end[i][1]=first[i][1];
            }
        else{
            if(i%l==0){
            for(int j=i;j<i+l;j++){
            end[i+i+l-1-j][0]=first[j][0];
            end[i+i+l-1-j][1]=first[j][1];
        }
        }
        }
    }
    for(int i=0;i<n;i++){
        if(i==0){
            printf("%05d %d",end[i][1],end[i][0]);
        }
        else{
         printf(" %05d\n%05d %d",end[i][1],end[i][1],end[i][0]);
           
        }
    }
    cout<<" -1"<<endl;
    return 0;
    return 0;
}