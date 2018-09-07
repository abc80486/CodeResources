#include<iostream>
using namespace std;
const string da[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
    string a,b,c,d;
    int k=1;
    cin>>a>>b>>c>>d;
    int t=a.length()<b.length()?a.length():b.length();
    for(int i=0;i<t;i++){
        if(a[i]==b[i])
            if(k==2)
            {   
                if(a[i]>='A' && a[i]<='N'){
                    printf(" %02d",a[i]-'A'+10);   break;}
                if(a[i]>='0'&&a[i]<='9'){
                    printf(" %02d",a[i]-'0');  break;}
            }
            else if(k==1 && a[i]>='A' && a[i]<='G'){
                cout<<da[a[i]-'A'];k=2;
            }
    }
    t=c.length()<d.length()?c.length():d.length();
    for(int i=0;i<t;i++){
        if(c[i]==d[i] && ((c[i]>='a'&&c[i]<='z') || (c[i]>='A'&&c[i]<='Z')) ){
            printf(":%02d",i); break;
        }
    }
    return 0;
}
