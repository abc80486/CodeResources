#include<iostream>
using namespace std;
int LPS_dp(char s[], int len){//最长回文字串动态规划算法
    int dp[len][len];
    int ans=1;
    dp[len-1][len-1]=1;
    for(int i=0;i<len-1;++i){
        dp[i][i]=1;
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            ans=2;
        }
    }
    for(int k=3;k<=len;++k){
        for(int i=0;i+k-1<len;++i){
            int j;
            j=i+k-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
                ans=k;
            }
        }
    }
    return ans;
}