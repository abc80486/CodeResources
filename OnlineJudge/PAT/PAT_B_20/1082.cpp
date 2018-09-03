#include<iostream>
using namespace std;
const double MAX__=1000000;
int main(){
    int n;
    scanf("%d",&n);
    double max=0.0,min=MAX__;
    char maxname[10],minname[10];
    while(n--){
        double a,b;char ch[10];
        scanf("%s%lf%lf",ch,&a,&b);
        a=a*a+b*b;
        if(a>max) {max=a;
            int i;
            for(i=0;ch[i]!='\0';i++){
                maxname[i]=ch[i];
            }
            maxname[i]='\0';
        }
        if(a<min) {min=a;
            int i;
            for(i=0;ch[i]!='\0';i++){
                minname[i]=ch[i];
            }
            minname[i]='\0';
        }
    }
    cout<<minname<<" "<<maxname<<endl;
    return 0;
}