class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> s(amount+1,9999999);
        s[0]=0;
        
        for(int &i:coins){
            int j=i;
            while(j<amount+1){
                s[j]=min(s[j-i]+1,s[j]);
                j++;
            }
        }
        if(s[amount]==9999999)
            return -1;
        return s[amount];
    }
};