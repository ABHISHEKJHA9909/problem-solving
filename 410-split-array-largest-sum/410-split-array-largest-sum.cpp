class Solution {
public:
    
    bool ispossible(vector<int>& nums,int x,int k){
        int s=0;
        for(int &i:nums){
            if(i>x)
                return 0;
            else
                if(s+i>x)
                    s=i,k--;
                else
                    s+=i;
        }
        return k>=1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int r=0,l=accumulate(nums.begin(),nums.end(),0);
        int res=0;
        while(r<=l){
            int mid=r+(l-r)/2;
            if(ispossible(nums,mid,m)){
                l=mid-1;
                res=mid;
            }
            else
                r=mid+1;
        }
        
        return res;
    }
};