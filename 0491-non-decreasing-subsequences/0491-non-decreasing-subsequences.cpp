class Solution {
public:
    bool isInc(vector<int>& arr){
        for(int i=1,n=arr.size();i<n;i++){
            if(arr[i-1]>arr[i])
                return false;
        }
        return true;
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        
        for(int i=0,n=nums.size();i<pow(2,n);i++){
            vector<int>curr;
            
            for(int j=0;j<n;j++){
                if((1<<j)&i){
                    curr.push_back(nums[j]);
                }
            }
            
            if(curr.size()>1 && isInc(curr) )
                s.insert(curr);
        }
        
        vector<vector<int>> res;
        for(auto &i:s)
            res.push_back(i);
        return res;
    }
};