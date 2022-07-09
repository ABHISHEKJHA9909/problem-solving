class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        
int ptr1=0, ptr2=0, n=nums.size();

        while(ptr1<n || ptr2<n){
          while(ptr2<n && nums[ptr2]!=0) ptr2++;
          ptr1=ptr2+1;
          while(ptr1<n && nums[ptr1]==0) ptr1++;

          if(ptr1>=n) break;

          swap(nums[ptr1], nums[ptr2]);
          ptr1++, ptr2++;
        }
    }
};