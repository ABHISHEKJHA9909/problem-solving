class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;
        int buyPrice=prices[0];
        
        for(int currPrice:prices){
            if(currPrice>buyPrice){
                profit+=(currPrice-buyPrice);
            }
            buyPrice=currPrice;
        }
        
        return profit;
    }
}