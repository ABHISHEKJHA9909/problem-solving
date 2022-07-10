class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev=0,pre_prev=0,n=cost.size();
        
        for(int i=0;i<n;i++){
            int curr=cost[i]+min(prev,pre_prev);
            pre_prev=prev;
            prev=curr;
        }
        
        return min(prev,pre_prev);
    }
};