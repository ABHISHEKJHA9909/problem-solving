class Solution {
    public List<List<Integer>> generate(int nums) {
        List<List<Integer>> res=new ArrayList<>();
        
        List<Integer> first=new ArrayList<Integer>();
        first.add(1);
        res.add(first);
        
        for(int i=2;i<=nums;i++){
            List<Integer> curr=res.get(res.size()-1);
            List<Integer> n=new ArrayList<Integer>();
            n.add(1);
            for(int j=1;j<curr.size();j++){
                n.add(curr.get(j)+curr.get(j-1));
            }
            n.add(1);
            res.add(n);
        }
        
        return res;
    }
}