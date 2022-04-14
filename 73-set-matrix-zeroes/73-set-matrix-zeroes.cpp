class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int r=arr.size(),c=arr[0].size();
        
        vector<vector<int>> res(r,vector<int>(c));
        res=arr;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==0){
                    for(int ii=0;ii<r;ii++){
                        res[ii][j]=0;
                    }
                    for(int ii=0;ii<c;ii++){
                        res[i][ii]=0;
                    }
                }
            }
        }
        
        arr=res;
    }
};