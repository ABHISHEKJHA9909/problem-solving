class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int len1=nums1.length;
        int len2=nums2.length;
        
        Stack<Integer>s=new Stack<>();
        Map<Integer,Integer>m=new HashMap<Integer,Integer>();
        
        for(int i=len2-1;i>=0;i--){
            while(!s.empty() && (nums2[s.peek()]<=nums2[i])){
                s.pop();
            }
                
            if(s.empty()){
                m.put(nums2[i],-1);
            }
            else{
                m.put(nums2[i],nums2[s.peek()]);
            }
            s.push(i);
        }
        
        int res[]=new int[len1];
        
        
        for(int i=0;i<len1;i++){
            res[i]=m.get(nums1[i]);
        }
        
        
        return res;
    }
}