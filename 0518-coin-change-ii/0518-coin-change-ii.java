class Solution {
    Map<String,Integer>m=new HashMap<String,Integer>();
    
    
    private int rec(int i,int amount,int curr_amount,int[] coins){
        if(i==coins.length || curr_amount>amount)
            return 0;
        if(curr_amount==amount)
            return 1;
        
        String s=i+"_"+curr_amount;
        
        if(m.get(s)!=null)
            return m.get(s);
        
        int taken=rec(i,amount,curr_amount+coins[i],coins);
        int not_taken=rec(i+1,amount,curr_amount,coins);
        
        m.put(s,taken+not_taken);
        return taken+not_taken;
    }
    
    public int change(int amount, int[] coins) {
        return rec(0,amount,0,coins);
    }
}