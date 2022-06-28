class Solution {
    public int[] twoSum(int[] arr, int target) {
        int i=0,j=arr.length-1;
        while(arr[i]+arr[j]!=target){
            if(arr[i]+arr[j]<target)
                i++;
            else
                j--;
        }
        int res[]={i+1,j+1};
        return res;
    }
}