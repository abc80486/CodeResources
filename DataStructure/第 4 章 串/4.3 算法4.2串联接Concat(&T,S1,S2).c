#define MAXSTRLEN 255
    //定义串的最大串长；
typedef unsigned char SString[MAXSTRLEN+1];
    //0号单元存放串的长度；
Status Concat(SString &T,SString S1,SString S2){
    //用T返回由S1和S2联接而成的新串。若截断，返回false;
    if (S1[0]+S2[0] <= MAXSTRLEN){
        //两串长度和低于最大长度；
        T[1..S1[0]]=S1[1..S1[0]];
        //将串1复制到新串；
        T[S1[0]+1...S1[0]+S2[0]]=S2[1..S2[0]];
        //将串2复制到新串；
        T[0]=S1[0]+S2[0]; uncut = TRUE;
        //设置新串长度；标志串信息的完整性；
    }
    else if(S1[0]<MAXSTRLEN){
        //两串长度和大于新串最大存储空间；串1长度小于新串；优先保留串1；
        T[1..S1[0]]=S1[1..S1[0]];
        //将串1复制到新串；
        T[S1[0]+1..MAXSTRLEN]=S2[1..MAXSTRLEN-S1[0]];
        //将新串余下空间存放串2；
        T[0]=MAXSTRLEN;uncut=FALSE;
        //设置新串长度；标志信息不完整（串2被截）；
    }
    else{
        //串1长度大于新串最大存储空间
        T[0..MAXSTRLEN]=S1[0..MAXSTRLEN];
        //将串1部分复制到新串；
        uncut = FALSE;
        //标志信息不完整，没有串2；
    }
    return uncut;//返回串完整的标志；
}