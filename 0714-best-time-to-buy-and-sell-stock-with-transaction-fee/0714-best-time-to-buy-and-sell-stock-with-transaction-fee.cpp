class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int x=0,y=INT_MIN;
        
        for(int i=0;i<prices.size();i++){
            int tmp=x;
            x=max(x,y+prices[i]);
            y=max(y,x-prices[i]-fee);
        }
        
        return x;
    }
};