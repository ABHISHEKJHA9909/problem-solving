class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        
        //road count of each node
        int cnt[]=new int[n];
        int mat[][]=new int[n][n];
        
        
        for(int i=0;i<roads.length;i++){
            int n1=roads[i][0];
            int n2=roads[i][1];
            
            mat[n1][n2]=1;
            mat[n2][n1]=1;
            
            ++cnt[n1];
            ++cnt[n2];
        }
        
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res=Math.max(res,cnt[i]+cnt[j]-mat[i][j]);
            }
        }
        
        return res;
    }
}