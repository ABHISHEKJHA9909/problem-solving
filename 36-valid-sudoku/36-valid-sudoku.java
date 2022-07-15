class Solution {
    char arr[][]=new char[9][9];
    int m=0,n=0;
    
    boolean check(int ii,int jj){
        for(int i=ii+1;i<9;i++)if(arr[i][jj]==arr[ii][jj])return false;
        for(int j=jj+1;j<9;j++)if(arr[ii][j]==arr[ii][jj])return false;
        int x=(ii/3)*3,y=(jj/3)*3;
        for(int i=x;i<x+3;i++)
            for(int j=y;j<y+3;j++)
                if( !(i==ii && j==jj) && arr[i][j]==arr[ii][jj])
                    return false;
        return true;
    }
    
    public boolean isValidSudoku(char[][] board) {
        m=board.length;
        n=board[0].length;
        
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)arr[i][j]=board[i][j];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]!='.' && check(i,j)==false){
                    return false;
                }
            }
        }
        
        return true;
    }
}