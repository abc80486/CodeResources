//没能弄懂！！！
int Index_KMP(SString S,SString T,int pos){
    i=pos;j=1;
    while(i<=S[0] && j<=T[0]){
        if(j==0 || S[i]==T[j]){
            ++i;++j;
        }
        //j==0为一种特殊情况；
        else j=next[j];
    }
    if(j>T[0]) return i-T[0];
    else return 0;
}
void get_next(SString T,int next[]){
    i=1;next[1]=0;j=0;
    while(i<T[0]){
        if(j==0 || T[i]==T[j])
            ++i;++j;next[i]=j;
        else j=next[j];
    }
}
void get_nextval(SString T,int nextval[]){
    i=1;nextval[1]=0;j=0;
    while(i<T[0]){
        if(j==0 || T[i] == T[j]){
            ++i;++j;
            if(T[i]!=T[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
    }
}