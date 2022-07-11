class Solution {
    public int trap(int[] arr) {
        int n=arr.length;
        int i=0,j=n-1,im=arr[i],jm=arr[j],res=0;
        
        while(i<j){
            im=Math.max(im,arr[i]);
            jm=Math.max(jm,arr[j]);
            
            res+=Math.min(im,jm)-Math.min(arr[i],arr[j]);
            
            if(arr[i]<arr[j])
                i++;
            else
                j--;
        }
        
        return res;
    }
}