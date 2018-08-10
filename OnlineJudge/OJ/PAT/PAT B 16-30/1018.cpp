#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int aw=0,ap=0,al=0;
    scanf("%d",&n);
    char a,b;
    int a1[3]={0},b1[3]={0};
    while(n--){
        cin>>a>>b;
        if(a==b){ap++;}
        else{
        if(a=='C'&&b=='J'){aw++;a1[1]++;}
        else if(a=='C'&&b=='B'){al++;b1[0]++;}
        else if(a=='J'&&b=='C'){al++;b1[1]++;}
        else if(a=='J'&&b=='B') {aw++;a1[2]++;}
        else if(a=='B'&&b=='C') {aw++;a1[0]++;}
        else {al++;b1[2]++;}
        }
    }
    printf("%d %d %d\n",aw,ap,al);
    printf("%d %d %d\n",al,ap,aw);
    int k=0;
    for(int i=1;i<3;i++){
        if(a1[i]>a1[k]) k=i;
    }
    if(k==0) cout<<'B'<<" ";
    if(k==1) cout<<'C'<<" ";
    if(k==2) cout<<'J'<<" ";
    k=0;
    for(int i=1;i<3;i++){
        if(b1[i]>b1[k]) k=i;
    }
    if(k==0) cout<<'B';
    if(k==1) cout<<'C';
    if(k==2) cout<<'J';
    return 0;
}