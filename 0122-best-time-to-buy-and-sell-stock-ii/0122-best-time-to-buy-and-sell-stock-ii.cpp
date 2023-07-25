class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0,buy=INT_MIN;
        
        for(int &i:prices){
            buy=max(buy,sell-i);
            sell=max(sell,buy+i);
        }
        
        return sell;
    }
};