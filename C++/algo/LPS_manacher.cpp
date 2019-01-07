#include<iostream>
#include<cstring>
using namespace std;
void manacher(char s[],int p[],int len){
    char s_new[2*len+3];
    s_new[0]='$';s_new[1]='#';
    int j=2;
    for(int i=0;i<len;i++){
        s_new[j++]=s[i];
        s_new[j++]='#';
    }
    s_new[j]='\0';
    len=j;
    int id,mx=0;
    for(int i=1;i<len;i++){
        if(i<mx) p[i]=min(p[2*id-i],mx-1);
        else p[i]=1;
        while(s_new[i-p[i]]==s_new[i+p[i]]) p[i]++;
        if(mx<i+p[i]){
            id=i;
            mx=i+p[i];
        }
    }
}
void manacher2(char str[],int len[],int n){
    len[0]=1;
    for(int i=1;j=0;i<(n<<1)-1;++i){
        int p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1 && q+len[i]<n && str[p-len[i]]==str[q+len[i]])
        ++len[i];
        if(q+len[i]-1>r) j=i;
    }
}
int main(){
    char s[];
    scanf("%s",s);
    int n=strlen(s);
    int p[200]={0};
    int num=0,k=0;
    manacher(s,p,n);
    for(int i=1;i<=2*n;i++)
        if(p[i]-1>num){
            num=p[i]-1;
            k=i;
        }
    for(int i=(k-num)/2;i<num;i++){
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}