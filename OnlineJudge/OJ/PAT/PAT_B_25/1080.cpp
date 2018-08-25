//mooc期终成绩
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string.h>
using namespace std;
struct student{
    char name[20];
    double gg;
    bool operator < (const student &a) const{
           if(strcmp(name,a.name)<0){
               return true;
           }
           else return false;
        }
};
struct stuout{
    char name[20];
    double gp,gm,gn,g;
    bool operator < (const stuout &a) const{
        if(this->g!=a.g) return this->g > a.g;
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
    //student gp[p],gm[m],gn[n];
    set<struct student> gp,gm,gn;
    set<struct stuout> g;
    while(p--){
        student ch;
        scanf("%s%lf",ch.name,&ch.gg);
        if(ch.gg>=200) gp.insert(ch);
    }
    while(m--){
        student ch;
        scanf("%s%lf",ch.name,&ch.gg);
        gm.insert(ch);
    }
    while(n--){
        student ch;
        scanf("%s%lf",ch.name,&ch.gg);
        if(ch.gg>=36) gn.insert(ch);
    }
    set<struct student>::iterator gpit=gp.begin(),
        gmit=gm.begin(),gnit=gn.begin();
    for(;gnit!=gn.end();gnit++){
        stuout ch;
        int ta=1;
        while(strcmp((*gpit).name,(*gnit).name)>=0){
        if(strcmp((*gpit).name,(*gnit).name)==0){
            int tag=1;
            while(strcmp((*gnit).name,(*gmit).name)>=0){
                if(strcmp((*gmit).name,(*gnit).name)==0){
                    strcpy(ch.name,(*gpit).name);
                    ch.gp=(*gpit).gg;
                    ch.gm=(*gmit).gg;
                    ch.gn=(*gnit).gg;
                    ch.g=ch.gm*0.4+ch.gn*0.6;
                    if(ch.g>=60) g.insert(ch);
                    tag=0;
                 }
                 gmit++;
                 if(gmit==gm.end()) break;
                 
            }
            if(tag==1){
                if((*gnit).gg>=60){
                   strcpy(ch.name,(*gpit).name);
                    ch.gp=(*gpit).gg;
                    ch.gm=-1;
                    ch.gn=(*gnit).gg; 
                    g.insert(ch);
                }
            }
        }
        gnit++;
        if(gnit == gn.end()) break;
        }
        gpit++;
    }
    for(set<struct stuout>::iterator it=g.begin();it!=g.end();it++){
        printf("%s\n",(*it).name);
    }

    return 0;
}
/*
3 3 3
abh 234
jiu 656
aaa 587
*/