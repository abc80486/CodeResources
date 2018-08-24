#include<iostream>
using namespace std;
struct stu{
    char num[20];
    int second;
    int first;
};
int main(){
    int n;
    scanf("%d",&n);
    stu a[n];
    for(int i=0;i<n;i++){
        scanf("%s %d %d",a[i].num,&a[i].second,&a[i].first);
    }
    //cout<<a[1].first<<endl;
    int m;
    scanf("%d",&m);
    while(m--){
        int ch;
        scanf("%d",&ch);
        for(int i=0;i<n;i++){
            if(ch==a[i].second){
                printf("%s %d\n",a[i].num,a[i].first);break;
            }
        }
    }
    return 0;
}