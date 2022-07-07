class Solution {
    String s1,s2,s3;
    int [][]dp={};
    int search(int i,int j,int k){
        if(k==s3.length())
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i<s1.length() && s1.charAt(i)==s3.charAt(k) && search(i+1,j,k+1)==1){
            dp[i][j]=1;
            return dp[i][j];
        }
        if(j<s2.length() && s2.charAt(j)==s3.charAt(k) && search(i,j+1,k+1)==1){
            dp[i][j]=1;
            return dp[i][j];
        }
        dp[i][j]=0;
        return dp[i][j];
    }
    public boolean isInterleave(String s11, String s22, String s33) {
        s1=s11;
        s2=s22;
        s3=s33;
        dp=new int[s1.length()+1][s2.length()+1];
        for(int i=0;i<s1.length()+1;i++)for(int j=0;j<s2.length()+1;j++)dp[i][j]=-1;
        if(s1.length()+s2.length()==s3.length())
            return search(0,0,0)==1;
        return false;
    }
}