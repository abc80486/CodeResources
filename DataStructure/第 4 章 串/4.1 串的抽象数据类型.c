ADT String{
    数据对象：D={ai|ai<-CharacterSet,i=1,2,...,n,n>=0}
    数据关系：R={<a(i-1),ai>|a(i-1),ai<-D,i=1,2,...,n}
    基本操作：
        StrAssign(&T,chats)
        StrCopy(&T,S)
        StrEmpty(S)
        StrCompare(S,T)
        StrLength(S)
        ClearString(&S)
        Concat(&T,S1,S2)
        SubString(&Sub,S,pos,len)
        Index(S,T,pos)
        Respace(&S,T,V)
        StrInsert(&S,pos,T)
        StrDelete(&S,pos,len)
        DestroyString(&S)
}