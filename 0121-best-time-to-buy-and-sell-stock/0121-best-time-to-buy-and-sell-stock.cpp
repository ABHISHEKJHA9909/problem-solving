class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mn=arr[0],res=0;
        
        for(int i:arr){
            res=max(res,(i-mn));
            mn=min(mn,i);
        }
        
        return res;
    }
};