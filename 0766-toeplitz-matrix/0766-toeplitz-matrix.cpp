class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& arr) {
        int n=arr[0].size(),m=arr.size();
        
        for(int k=0;k<m;k++){
            int i=k,j=0;
            while(i<m && j<n){
                if(arr[i][j]!=arr[k][0])
                    return false;
                ++i,++j;
            }
        }
        for(int k=0;k<n;k++){
            int i=0,j=k;
            while(i<m && j<n){
                if(arr[i][j]!=arr[0][k])
                    return false;
                ++i,++j;
            }
        }
        
        return true;
    }
};