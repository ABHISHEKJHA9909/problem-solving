class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        
        vector<vector<int>>res(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res[j][n-i-1]=arr[i][j];
            }
        }
        
        arr=res;
    }
};