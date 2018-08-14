#include<iostream>
#include<string>
const int N=100;
using namespace std;
int main(){
    char a[N][20],ch;
    int k=0;
    while((ch=getchar())!=10){
        if(ch!=' '){
             int t=0;
             while(ch!=' '&&ch!='\n'){
                 a[k][t++]=ch;ch=getchar();
             }
             k++;
        }
        if(ch=='\n') break;
    }
    for(int i=k-1;i>=0;i--){
        if(i!=k-1) cout<<" ";
        printf("%s",a[i]);
    }
    cout<<endl;
    return 0;
}
