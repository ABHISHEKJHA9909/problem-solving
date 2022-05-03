class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int []copy=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            copy[i]=nums[i];
        }
        Arrays.sort(copy);
        int i=0,j=nums.length -1 ;
        while(i<j && nums[i]==copy[i]){
            i++;
        }
        while(j>i && nums[j]==copy[j]){
            j--;
        }
        if(i==j)
            return 0;
        return j-i+1;
    }
}