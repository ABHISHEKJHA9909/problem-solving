class Solution {
    public int candy(int[] arr) {
        int len=arr.length;
        
        int res[]=new int[len];
        res[0]=1;
        for(int i=1;i<len;i++){
            if(arr[i-1]<arr[i]){
                res[i]=res[i-1]+1;
            }
            else{
                res[i]=1;
            }
        }
        
        
        for(int i=len-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                res[i]=Math.max(res[i+1]+1,res[i]);
            }
        }
        
        int result=0;
        for(int i:res){
            result+=i;
        }
        
        return result;
    }
}