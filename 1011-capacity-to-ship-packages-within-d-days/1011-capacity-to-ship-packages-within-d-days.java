class Solution {
    int find(int[] arr,int d){
        int sum=0,res=1,n=arr.length;
        for(int i=0;i<n;i++){
            if(sum+arr[i]>d){
                res++;
                sum=0;
            }
            sum+=arr[i];
        }
        return res;
    }
    
    public int shipWithinDays(int[] weights, int days) {
        int i=0,j=Integer.MAX_VALUE,res=Integer.MAX_VALUE;
        for(int k:weights)
            i=Math.max(i,k);
        
        while(i<=j){
            int mid=i+(j-i)/2;
            int curr=find(weights,mid);
            // System.out.println(mid+" "+curr);
            if(curr<=days){
                res=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        
        return res;
    }
}