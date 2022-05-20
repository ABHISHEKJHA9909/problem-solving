class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x=INT_MAX,y=INT_MAX,z=INT_MAX,n=nums.size();
        
        for(int i=0;i<n;i++){
            int curr=nums[i];
            
            if(curr<x)
                x=curr;
            if(curr<y && curr>x)
                y=curr;
            if(curr>y)
                return true;
                
        }
        
        return false;
    }
};