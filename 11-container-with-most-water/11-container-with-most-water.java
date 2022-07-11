class Solution {
    public int maxArea(int[] arr) {
        int res=0;              //to store result(currrently - 0)
        
        int i=0,j=arr.length-1; //pointer to begin and end of array
        
        while(i<j){
            res=Math.max(res,(j-i)*(Math.min(arr[i],arr[j])));
            if(arr[i]<arr[j])
                i++;
            else
                j--;;
        }
        
        
        
        return res;
    }
}