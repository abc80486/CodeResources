#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int ch;
    char a[5];
    scanf("%s",a);
    ch=atoi(a);
    
    
   // printf("%s\n",maxx);return 0;
   char maxx[5],minn[5];
    strcpy(maxx,a);strcpy(minn,a);
    while(ch!=6174){
        sort(minn,minn+4);sort(maxx,maxx+4,greater<int>());
        ch=atoi(maxx)-atoi(minn);
        if(a[0]==a[1]&&a[2]==a[3]&&a[1]==a[2]){
            printf("%s - %s = 0000",a,a);
        }
        else{
            
        }
    }
    return 0;
}