class Solution {
    public int trap(int[] arr) {
        int i=0,j=arr.length-1;
        int lmax=0,rmax=0,res=0;
        
        while(i<j){
            if(arr[i]<arr[j]){
                if(lmax<arr[i])
                    lmax=arr[i];
                else
                    res+=lmax-arr[i];
                i++;
            }
            else{
                if(rmax<arr[j])
                    rmax=arr[j];
                else
                    res+=rmax-arr[j];
                j--;
            }
        }
        return res;
    }
}