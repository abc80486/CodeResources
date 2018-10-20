//判断相邻相等子串；参数char s[cur];
int chstr(char *S,cur){
    int ok = 1;
    for(int j = 1; j*2 <= cur+1; j++) {        
      int equal = 1;
      for(int k = 0; k < j; k++) 
        if(S[cur-k] != S[cur-k-j]) { equal = 0; break; }
      if(equal) { ok = 0; break; }              
    }
    return ok;
}