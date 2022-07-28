class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<int>arr(c,0);
        
        int res=0;
        
        for(int i=0;i<r;i++){
            
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0)
                    arr[j]=0;
                arr[j]+=matrix[i][j];
            }
            
            vector<int>curr=arr;
            sort(curr.begin(),curr.end());
            for(int j=0;j<c;j++){
                res=max(res,curr[j]*(c-j));
            }
            
        }
        
        return res;
    }
};