//链表元素分类
#include<iostream>
#include<vector>
using namespace std;
struct student{
    int value;
    int next;
};
int main(){
    int begin,n,k;
    student a[100000];
    scanf("%d%d%d",&begin,&n,&k);
    while(n--){
        int ch;
        scanf("%d",&ch);
        scanf("%d%d",&a[ch].value,&a[ch].next);
    }
    vector<struct student> min,mid,max;
    while(begin!=-1){
        int t=a[begin].value;
        student temp;
        temp.value=a[begin].value;
        temp.next=begin;
        if(t<0) min.push_back(temp);
        else if(t>k) max.push_back(temp);
        else mid.push_back(temp);
        begin=a[begin].next;
    }
    for(int i=0;i<min.size();i++){
        if(i==0) printf("%05d %d",min[i].next,min[i].value);
        else printf(" %05d\n%05d %d",min[i].next,min[i].next,min[i].value);
    }
   
    for(int i=0;i<mid.size();i++){
       printf(" %05d\n%05d %d",mid[i].next,mid[i].next,mid[i].value);
    }
    for(int i=0;i<max.size();i++){
        printf(" %05d\n%05d %d",max[i].next,max[i].next,max[i].value);
    }
    printf(" -1\n");
    return 0;
}
/*
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
*/