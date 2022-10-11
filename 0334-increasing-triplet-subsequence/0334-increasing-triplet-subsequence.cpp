class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX,b=INT_MAX,curr=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            curr=nums[i];
            if(curr<a)
                a=curr;
            else if(curr>a && curr<b)
                b=curr;
            else if(curr>b)
                return true;
        }
        
        return false;
    }
};