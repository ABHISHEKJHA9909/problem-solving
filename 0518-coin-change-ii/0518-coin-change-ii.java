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
        int n=coins.length;
        
        int dp[][]=new int[n+1][amount+1];
        
        dp[0][0]=1;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0||j==0){
                    if(i==0 && j==0){
                        continue;
                    }
                    else if(i==0){
                        dp[i][j]=0;
                    }
                    else{
                        dp[i][j]=1;
                    }
                }
                else{
                    if(j>=coins[i-1]){
                        dp[i][j]=dp[i][j-coins[i-1]] + dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][amount];
    }
}