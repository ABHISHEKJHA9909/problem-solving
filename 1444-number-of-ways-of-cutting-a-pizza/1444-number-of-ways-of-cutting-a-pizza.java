class Solution {
    final int MOD=1000000007;
    
    int rec(int i,int j,int r,int c,int k,Integer[][][] dp,int[][] pre){
        if(pre[i][j]==0)
            return 0;
        if(k==0)
            return 1;
        if(dp[i][j][k]!=null)
            return dp[i][j][k];
        
        int sum=0;
        
        for(int ii=i+1;ii<r;ii++)
            if(pre[i][j]-pre[ii][j]>0)
                sum=(sum+rec(ii,j,r,c,k-1,dp,pre))%MOD;
        
        for(int jj=j+1;jj<c;jj++)
            if(pre[i][j]-pre[i][jj]>0)
                sum=(sum+rec(i,jj,r,c,k-1,dp,pre))%MOD;
        // System.out.println(i+" "+j+" "+k);
        return dp[i][j][k]=sum;
    }
    
    public int ways(String[] arr, int k) {
        int r=arr.length,c=arr[0].length();
        
        Integer dp[][][]=new Integer[r][c][k];
        int pre[][]=new int[r+1][c+1];
        
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                pre[i][j]=pre[i][j+1]+pre[i+1][j]-pre[i+1][j+1]+((arr[i].charAt(j)=='A')?1:0);
            }
        }
        
        return rec(0,0,r,c,k-1,dp,pre);
    }
}