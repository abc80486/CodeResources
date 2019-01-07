#include<cstring>
int LCS_dp(char str1[],char str2[]){//最长公共子序列，动态规划法
    int i,j,length1,length2;
    length1=strlen(str1);
    length2=strlen(str2);
    int **c=new int*[length1+1];
    for(i=0;i<length1+1;i++) c[i]=new int[length2+1];
    for(i=0;i<length1+1;i++) c[i][0]=0;
    for(j=0;j<length2+1;j++) c[0][j]=0;
    for(i=1;i<length1+1;i++){
        for(j=1;j<length2+1;j++){
            if(str1[i-1]==str2[j-1]) c[i][j]=c[i-1][j-1]+1;
            else if(c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
            else c[i][j]=c[i][j-1];
        }
    }
    for(i=0;i<length1+1;++i) delete[] c[i];
    delete[] c;
    return c[length1][length2];
}