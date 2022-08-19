class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>l;
        unordered_map<int,int>e;
        
        for(int i:nums){
            l[i]++;
        }
        
        for(int i:nums){
            if(l[i]==0)continue;
            l[i]--;
            if(e[i-1]>0){
                e[i-1]--;
                e[i]++;
            }
            else if(l[i+1]>0 && l[i+2]>0){
                l[i+1]--;
                l[i+2]--;
                e[i+2]++;
            }
            else
                return false;
        }
        
        return true;
    }
};