class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int cnt=0,diff=-1,curr=1;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]!=diff){
                int x=curr-3+1;
                curr=0;
                if(x>0){
                    cnt+=(x*(x+1))/2;
                }
                curr=2;
                diff=arr[i]-arr[i-1];
            }
            else{
                curr++;
            }
        }
        int x=curr-3+1;
        curr=0;
        if(x>0){
            cnt+=(x*(x+1))/2;
        }
        
        return cnt;
    }
};