class Solution {
public:
    int maxJump(vector<int>& arr) {
        int res=arr[1]-arr[0];
        
        for(int i=2;i<arr.size();i++){
            res=max(res,arr[i]-arr[i-2]);
        }
        
        return res;
    }
};