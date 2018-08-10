#include<iostream>
//#include<string.h>
//#include<algorithm>
using namespace std;
struct student{
    string name;
    string num;
    int score;
};
int main(){
    int n;
    student maxs,mins;
    maxs.score=0;mins.score=100;
    cin>>n;
    while(n--){
        student ch;
        cin>>ch.name>>ch.num>>ch.score;
        //scanf("%s%s%d",ch.name,ch.num,&ch.score);
        if(ch.score>maxs.score){
            //memcpy(&maxs,&ch,sizeof(struct student));
            maxs.name=ch.name;
            maxs.num=ch.num;
            maxs.score=ch.score;
        }
        if(ch.score<mins.score){
            //memcpy(&mins,&ch,sizeof(struct student));
            mins.name=ch.name;
            mins.num=ch.num;
            mins.score=ch.score;
        }
    }
    cout<<maxs.name<<" "<<maxs.num<<endl;
    cout<<mins.name<<" "<<mins.num<<endl;
    return 0;
}