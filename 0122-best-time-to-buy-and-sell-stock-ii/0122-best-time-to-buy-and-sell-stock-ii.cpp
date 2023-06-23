class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int x=INT_MAX,y=0;
        for(int &i:prices){
            x=min(x,i);
            if(i>x){
                y+=i-x;
                x=i;
            }
        }
        
        return y;
    }
};