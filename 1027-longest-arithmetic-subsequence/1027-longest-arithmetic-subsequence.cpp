class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        
        vector<vector<int>>m(n,vector<int>(2000));
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=nums[j]-nums[i] + 1000;
                m[j][diff]=m[i][diff]+1;
                res=max(res,m[j][diff]);
            }
        }
        
        return res+1;
    }
};