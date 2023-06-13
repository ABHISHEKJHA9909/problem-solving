class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),res=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int z=0;
                while(z<n && grid[i][z]==grid[z][j])
                    z++;
                if(z==n)
                    res++;
            }
        }
        
        return res;
    }
};