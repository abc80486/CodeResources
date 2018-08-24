Status SubString(SString $Sub,SString S,int pos,int len){
    //用Sub返回串S的第pos个字符起长度为len的子串；
    if(pos<1 || pos>S[0] ||len<0 ||len>S[0]-pos+1])
        return ERROR;
    //考虑边界条件；字符的起始位置条件；字符的长度与主串大小的限定；
    Sub[1..len]=S[pos..pos+len-1];
    //将主串的部分内容复制到子串；
    Sub[0]=len;
    //设置子串的大小；
    return OK;
}