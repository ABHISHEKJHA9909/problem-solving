class Solution {
    public int findMin(int[] arr) {
        int i=0,j=arr.length-1,res=Integer.MAX_VALUE;
        
        while(i<=j){
            int mid=(i+j)>>1;
            // System.out.println(i+" "+j+" "+mid);
            
            if(arr[j]<arr[mid])
                i=mid+1;
            else
                j=mid-1;
            res=Math.min(res,arr[mid]);
        }
        
        return res;
    }
}