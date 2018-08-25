//mooc期终成绩
#include<iostream>
#include<algorithm>
#include<set>
#include<string.h>
using namespace std;
struct student{
    char name[20];
    int gg;
    bool operator < (const student &a) const{
           if(strcmp(name,a.name)<0){
               return true;
           }
           else return false;
        }
};
struct stuout{
    char name[20];
    int gp,gm,gn,g;
    bool operator < (const stuout &a) const{
        if((this->g)!=a.g) return (this->g) > (a.g);
        else {
            if(strcmp(this->name,a.name)<0){
                return true;
            }
            else return false;
        }
    }
};
int main(){
    int p,m,n;
    scanf("%d%d%d",&p,&m,&n);
    set<struct student> gp,gm,gn;
    set<struct stuout> outp;
    while(p--){
        student ch;
        scanf("%s%d",ch.name,&ch.gg);if(ch.gg>=200) gp.insert(ch);
    }
    while(m--){
        student ch;
        scanf("%s%d",ch.name,&ch.gg);gm.insert(ch);
    }
    while(n--){
        student ch;
        scanf("%s%d",ch.name,&ch.gg);if(ch.gg>=30) gn.insert(ch);
    }
    set<struct student>::iterator gpit=gp.begin(),
        gmit=gm.begin(),gnit=gn.begin();
   for(;gpit!=gp.end();gpit++){
       stuout ch;
       for(;gnit!=gn.end();gnit++){
           if(strcmp((*gpit).name,(*gnit).name)==0){//找到匹配；
            for(;gmit!=gm.end();gmit++){
               //找到元素
               if(strcmp((*gnit).name,(*gmit).name)==0){
                   ch.gm=(*gmit).gg;
                   ch.gn=(*gnit).gg;
                   if(ch.gm>ch.gn) ch.g=ch.gm*0.4+ch.gn*0.6+0.5;
                   else ch.g=ch.gn;
                   if(ch.g>=60){
                     strcpy(ch.name,(*gpit).name);
                     ch.gp=(*gpit).gg;
                     outp.insert(ch);
                    }
                    gmit++;
                    break;
               }
               //找不到元素
               if(strcmp((*gnit).name,(*gmit).name)<0){
                   ch.gm=-1;
                   ch.gn=(*gnit).gg;
                   ch.g=ch.gn;
                   if(ch.g>=60){
                     strcpy(ch.name,(*gpit).name);
                     ch.gp=(*gpit).gg;
                     outp.insert(ch);
                    }
                    break;
                }  
            }
            gnit++;//指向下一个位置；
            break;
           }
           if(strcmp((*gpit).name,(*gnit).name)<0){//没找到匹配；
               break;
           }
        }
        if(gmit==gm.end() || gnit==gn.end()) break;
    }
    for(set<struct stuout>::iterator it=outp.begin();it!=outp.end();it++){
        printf("%s %d %d %d %d\n",(*it).name,(*it).gp,
            (*it).gm,(*it).gn,(*it).g);
    }

    return 0;
}
/*
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
*/