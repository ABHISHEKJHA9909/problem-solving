class Solution {
public:
    int change(int amount, vector<int>& arr) {
        int dp[50001]={0};
        dp[0]=1;
        
        for(int &c:arr){
            for(int i=c;i<=amount;i++){
                dp[i]+=dp[i-c];
            }
        }
        
        return dp[amount];
    }
};