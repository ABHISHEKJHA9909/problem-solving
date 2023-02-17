class Solution {
    int target=0;
    
    boolean rec(int[] arr,int i,int []sum){
        if(i==-1){
            return true;
        }
        for(int j=0;j<4;j++){
            if(sum[j]+arr[i]>target || (j>0 && sum[j]==sum[j-1]))
                continue;
            sum[j]+=arr[i];
            if(rec(arr,i-1,sum))
                return true;
            sum[j]-=arr[i];
        }
        return false;
    }
    
    public boolean makesquare(int[] arr) {
        for(int i:arr)
            target+=i;
        if(target%4!=0)
            return false;
        target/=4;
        Arrays.sort(arr);
        return rec(arr,arr.length-1,new int[4]);
    }
}