class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer>s=new HashSet<Integer>();
        
        for(int i:nums2){
            s.add(i);
        }
        
        List<List<Integer>> res=new ArrayList<>();
        res.add(new ArrayList<>());
        res.add(new ArrayList<>());
        
        for(int i:nums1){
            if(!s.contains(i)){
                res.get(0).add(i);
                s.add(i);
            }
        }
        
        s.clear();
        
        for(int i:nums1){
            s.add(i);
        }
        
        for(int i:nums2){
            if(!s.contains(i)){
                res.get(1).add(i);
                s.add(i);
            }
        }
        
        
        
        return res;
    }
}