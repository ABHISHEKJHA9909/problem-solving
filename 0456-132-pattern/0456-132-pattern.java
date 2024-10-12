class Solution {
    public boolean find132pattern(int[] nums) {
        int len=nums.length;
        int[] min=new int[len];
        
        Stack<Integer> s=new Stack<>();
        
        for(int i=0,x=nums[0];i<len;++i){
            
            if(nums[i]<x){
                x=nums[i];
            }
            
            min[i]=x;
            
            while(!s.isEmpty() && nums[s.peek()] <= nums[i]){
                s.pop();
            }
            
            if(!s.isEmpty() && min[s.peek()]<nums[i]){
                return true;
            }
            
            s.push(i);
        }

        return false;
    }
}