int max_sub_sum_dp(int arr[],int n){
    int sum=0,thissum=0;
    for(int i=0;i<n;i++){
        thissum+=arr[i];
        if(thissum>sum) sum=thissum;
        else if(thissum<0) thissum=0;
    }
    return sum;
}