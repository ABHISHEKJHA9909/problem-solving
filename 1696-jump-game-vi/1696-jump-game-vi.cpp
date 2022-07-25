class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int>q{0};
        
        for(int i=1,n=nums.size();i<n;i++){
            
            nums[i]+=nums[q.front()];
            
            while(q.size() && nums[q.back()]<nums[i])
                q.pop_back();
            
            q.push_back(i);
            
            if(i-q.front()==k){
                q.pop_front();
            }
        }
        
        return nums.back();
    }
};