//字符图形
#include<iostream>
using namespace std;
int main(){
    int n,k;
    char c;
    cin>>n;
    cin>>c;
    if(n%2==0) k=n/2;
    else {k=n/2;k++;}
    //cout<<k<<endl;return 0;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
             if(i==0||i==(k-1))
                printf("%c",c);
            else{
                if(j==0||j==(n-1)) printf("%c",c);
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}