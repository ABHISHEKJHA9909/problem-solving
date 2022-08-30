class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int neg=0;
        for(int &i:nums){
            if(i>0){
                neg=i;
                break;
            }
        }
        if(neg==0){
            return 1;
        }
        for(int &i:nums){
            if(i<=0)
                i=neg;
        }
        
        for(int i:nums){
            cout<<i<<' ';
        }
        
        for(int &i:nums){
            int index=abs(i);
            if(index<=nums.size() && nums[index-1]>0){
                nums[index-1]*=-1;
                // cout<<index-1<<' ';
            }
        }
        
        for(int i=1;i<=nums.size();i++){
            if(nums[i-1]>0)
                return i;
        }
        
        return nums.size()+1;
    }
};