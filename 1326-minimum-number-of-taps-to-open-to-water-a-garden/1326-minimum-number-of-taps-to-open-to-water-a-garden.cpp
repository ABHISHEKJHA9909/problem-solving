class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>arr(n+1,0);
        
        for(int i=0;i<(n+1);i++){
            if(ranges[i]==0)
                continue;
            int l=max(0,i-ranges[i]);
            arr[l]=max(arr[l],min(n,i+ranges[i]));
        }

        int end=0,x=0;
        int result=0;
        
        for(int i=0;i<arr.size() && end<n;end=x){
            result++;
            
            while(i<arr.size() && i<=end){
                x=max(x,arr[i++]);
            }
            
            if(x==end)
                return -1;
        }
        
        return result;
    }
};