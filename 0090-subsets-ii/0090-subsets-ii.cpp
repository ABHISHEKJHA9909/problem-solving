class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>res={{}};
        res.push_back({nums[0]});
        int cnt=0;
        
        for(int i=1,k,n;i<nums.size();i++){
            n=res.size();
            
            if(nums[i]==nums[i-1]){
                if(cnt==false){
                    cnt=true;
                    k=res.size()/2;
                }
                for(int j=n-k;j<n;j++){
                    if(res[j].back()!=nums[i])
                        continue;
                    vector<int>curr=res[j];
                    curr.push_back(nums[i]);
                    res.push_back(curr);
                }
            }
            else{
                cnt=false;
                for(int j=0;j<n;j++){
                    vector<int>curr=res[j];
                    curr.push_back(nums[i]);
                    res.push_back(curr);
                }
            }
        }
        
        return res;
    }
};