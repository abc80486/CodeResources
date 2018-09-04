//互评成绩计算
#include<iostream>
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;
    int k=n;
    while(n--){
        int s1,max=0,min=s,p=0;
        double s2=0.0;
        cin>>s1;
        for(int i=1;i<k;i++){
            int ch;
            cin>>ch;
            if(ch>=0&&ch<=s){
                p++;
                s2+=ch;
                if(ch>max) max=ch;
                if(ch<min) min=ch;
            }
        }
        s2=(s2-max-min)/(p-2);
        cout<<int((s1+s2)/2+0.5)<<endl;

    }
    return 0;
}
/*
6 50
42 49 49 35 38 41
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29
*/