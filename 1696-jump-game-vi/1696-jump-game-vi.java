class Solution {
    public int maxResult(int[] nums, int k) {
        PriorityQueue<Integer>pq=new PriorityQueue<Integer>();
        PriorityQueue<Integer>temp=new PriorityQueue<Integer>();
        int n=nums.length;
        pq.add(-nums[0]);
        
        for(int i=1,j=0;i<n;i++){
            int curr=(-pq.peek()+nums[i]);
            pq.add(-curr);
            nums[i]=curr;
            if(i-j==k){
                temp.add(-nums[j]);
                while(temp.size()>0 && pq.size()>0 && temp.peek().intValue()==pq.peek().intValue()){
                    temp.remove();
                    pq.remove();
                }
                j++;
            }
        }
        
        return nums[n-1];
    }
}