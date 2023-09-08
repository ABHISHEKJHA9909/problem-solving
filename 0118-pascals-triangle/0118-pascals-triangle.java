class Solution {
    public List<List<Integer>> generate(int n) {
        List<List<Integer>> res=new ArrayList<>(n);
        
        res.add(Arrays.asList(1));
        if(n==1)
            return res;
        
        res.add(Arrays.asList(1,1));
        if(n==2)
            return res;
        
        for(int len=3;len<=n;++len){
            List<Integer>curr=new ArrayList<Integer>();
            
            curr.add(1);
            for(int i=0;i<len-2;i++){
                curr.add(res.get(len-2).get(i) + res.get(len-2).get(i+1));
            }
            curr.add(1);
            
            res.add(curr);
            
        }
        
        return res;
        
    }
}