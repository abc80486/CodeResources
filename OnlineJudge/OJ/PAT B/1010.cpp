#include<iostream>
using namespace std;
int main(){
    char ch,a[10];
    while((ch=getchar())!=10){
        int p=0,k=0;
        while(ch!=' '&&ch!=10) {
            a[k++]=ch;p++;
            ch=getchar();
        }
        for(int i=0;i<p;i++) {
            
            cout<<a[i];
        }
        cout<<" ";
        if(ch==10) break;
        
    }
    return 0;
} 