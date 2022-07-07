class Solution {
    String s1,s2,s3;
    int [][][]dp=new int[101][101][201];
    int search(int i,int j,int k){
        if(i==s1.length() && j==s2.length() && k==s3.length())
            return 1;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(i<s1.length() && j<s2.length() && s1.charAt(i)==s2.charAt(j) && s1.charAt(i)==s3.charAt(k)){
            dp[i][j][k]=search(i+1,j,k+1)|search(i,j+1,k+1);
            return dp[i][j][k];
        }
        if(i<s1.length() && s1.charAt(i)==s3.charAt(k)){
            dp[i][j][k]=search(i+1,j,k+1);
            return dp[i][j][k];
        }
        if(j<s2.length() && s2.charAt(j)==s3.charAt(k)){
            dp[i][j][k]=search(i,j+1,k+1);
            return dp[i][j][k];
        }
        dp[i][j][k]=0;
        return dp[i][j][k];
    }
    public boolean isInterleave(String s11, String s22, String s33) {
        s1=s11;
        s2=s22;
        s3=s33;
        for(int i=0;i<101;i++)for(int j=0;j<101;j++)for(int k=0;k<201;k++)dp[i][j][k]=-1;
        if(s1.length()+s2.length()==s3.length())
            return search(0,0,0)==1;
        return false;
    }
}