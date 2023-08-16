class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n=nums.length;
        int arr[]=new int[n-k+1];
        Deque<Integer>q=new LinkedList<Integer>();
        
        for(int i=0,j=0;i<n;++i){
            if(i>=k){
                //removal
                if(q.peekFirst()==nums[j])
                    q.removeFirst();
                
                
                j++;
            }
            
            
            while( (!q.isEmpty()) && q.peekLast()<nums[i]){
                q.removeLast();
            }
            
            q.addLast(nums[i]);
            
            arr[j]=q.peekFirst();
            
        }
        
        return arr;
    }
}