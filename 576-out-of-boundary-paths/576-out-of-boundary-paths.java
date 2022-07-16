class Solution {
    int arr[][][]=new int[51][51][51];
    int M=1000000007;
    
    int findPath(int m,int n,int mv,int i,int j){
        if(i<0||j<0||i==m||j==n)
            return 1;
        if(mv==0)
            return 0;
        if(arr[i][j][mv]!=-1)
            return arr[i][j][mv];
        arr[i][j][mv]= (
            (findPath(m,n,mv-1,i-1,j)+findPath(m,n,mv-1,i+1,j))%M+
            (findPath(m,n,mv-1,i,j-1)+findPath(m,n,mv-1,i,j+1))%M
            )%M;
        return arr[i][j][mv];
    }
    
    public int findPaths(int m, int n, int mv, int ii, int jj) {
        for(int i=0;i<51;i++)for(int j=0;j<51;j++)for(int k=0;k<51;k++)arr[i][j][k]=-1;
        return findPath(m,n,mv,ii,jj);
    }
} 