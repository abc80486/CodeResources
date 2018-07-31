
int Index(String S,String T,int pos){
    //T为非空串。若主串S中第pos个字符之后存在与T相等的子串，
    //则返回第一个这样的子串在S中的位置，否则返回0
    if(pos>0){
        n=StrLength(S);//求S的的长度；
        m=StrLength(T);//求T的长度；
        i=pos;//起始位置；
        while(i<=n-m+1){//循环n-m+1次；
            SubString(sub,S,i,m);//取S的子串；
            if(StrCompare(sub,T)!=0) ++i;//比较S的子串与已知串；
            else return i;//返回位置；
        }
    }
}