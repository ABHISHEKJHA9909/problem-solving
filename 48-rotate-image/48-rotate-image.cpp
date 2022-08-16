class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                swap(arr[i][j],arr[n-j-1][n-i-1]);
            }
        }
        
        for(int j=0;j<n;j++){
            for(int i=0;i<n/2;i++){
                swap(arr[i][j],arr[n-i-1][j]);
            }
        }
        
    }
};