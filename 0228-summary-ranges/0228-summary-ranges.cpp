class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        if(nums.size()==0)
            return res;
        
        int ans=0,temp=nums[0],curr=1,hi=nums[0];
        
        
        for(int i=1;i<nums.size();i++){
            if(temp+1!=nums[i]){
                hi=nums[i-1];
                if(curr==1){
                    res.push_back(to_string(hi));
                }
                else{
                    res.push_back(to_string(hi+(-curr+1))+"->"+to_string(hi));
                }
                curr=1;
            }
            else
                curr++;
            temp=nums[i];
        }
        hi=nums.back();
        if(curr==1){
            res.push_back(to_string(hi));
        }
        else{
            res.push_back(to_string(hi-curr+1)+"->"+to_string(hi));
        }
        
        return res;
    }
};