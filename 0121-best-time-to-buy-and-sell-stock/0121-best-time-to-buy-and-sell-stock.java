class Solution {
    public int maxProfit(int[] prices) {
        int len=prices.length;
        int res=0;
        int min=prices[0];
        
        for(int i=0;i<len;++i){
            min=prices[i]<min?prices[i]:min;
            res=prices[i]-min>res?prices[i]-min:res;
        }
        
        return res;
    }
}