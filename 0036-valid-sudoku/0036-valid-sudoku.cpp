class Solution {
public:
    
    bool row(vector<vector<char>>& board,int i,int j){
        int k=j+1;
        while(k!=9){
            if(board[i][k++]==board[i][j])
                return true;
        }
        return false;
    }
    
    bool col(vector<vector<char>>& board,int i,int j){
        int k=i+1;
        while(k!=9){
            if(board[k++][j]==board[i][j])
                return true;
        }
        return false;
    }
    
    bool box(vector<vector<char>>& board,int i,int j){
        int x=(i/3)*3,y=(j/3)*3;
        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                if(!(x+a==i&&y+b==j) && board[x+a][y+b]==board[i][j])
                    return true;
            }
        }
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && (row(board,i,j)||col(board,i,j)||box(board,i,j)))
                    return false;
            }
        }
        
        return true;
    }
};