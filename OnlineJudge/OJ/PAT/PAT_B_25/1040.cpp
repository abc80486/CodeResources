#include<iostream>
const int N=100000+5;
using namespace std;
void createat(int a[],int t[],int at[],int an,int tn){
    int i=0,j=0;
   while(i<an&&j<tn){
       if(a[i]<t[j]) {
           at[i]=tn-j;i++;
       }
       else j++; 
   }
}
void adjustat(int at[],int an){
    for(int i=an-2;i>=0;i--){
        at[i]=at[i]+at[i+1];
    }
}
void createpa(int p[],int a[],int pa[],int pn,int an,int at[]){
    int i=0,j=0;
    while(i<pn && j<an){
        if(p[i]<a[j]){
            pa[i]=at[j];i++;
        }
        else {j++;}
    }
}
int main(){
    int p[N],a[N],t[N];
    char ch;
    int k=0,pn=0,an=0,tn=0;
    while((ch=getchar())!=10){
        k++;
        if(ch=='P') p[pn++]=k;
        else if(ch=='A') a[an++]=k;
        else if(ch=='T') t[tn++]=k;
        else ;
    }
    int at[an]={0},pa[pn]={0};
    createat(a,t,at,an,tn);
    adjustat(at,an);
   createpa(p,a,pa,pn,an,at);
   int sum=0;
    for(int i=0;i<pn;i++){
        sum+=pa[i];
    }
    sum=sum%1000000007;
    cout<<sum<<endl;
    return 0;
}