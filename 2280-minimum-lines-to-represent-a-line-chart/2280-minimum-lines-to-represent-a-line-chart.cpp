class Solution {
public:
    
    int minimumLines(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==1)
            return 0;
        sort(arr.begin(),arr.end());
        
        int res=1;
        
        for(int i=2;i<n;i++){
            long long x1=arr[i-2][0],x2=arr[i-1][0],x3=arr[i][0];
            long long y1=arr[i-2][1],y2=arr[i-1][1],y3=arr[i][1];
            
            if((y1-y2)*(x2-x3)!=(x1-x2)*(y2-y3))
                res++;
        }
        
        return res;
    }
};