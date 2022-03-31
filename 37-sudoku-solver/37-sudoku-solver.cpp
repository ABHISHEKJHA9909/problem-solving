class Solution {
public:
    bool isvalid(vector<vector<char>>& arr,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(arr[i][col]==c)return false;
            if(arr[row][i]==c)return false;
            if(arr[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
        }
        return true;
    }
    
    bool rec(vector<vector<char>>& arr){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(arr[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(arr,i,j,c)){
                            arr[i][j]=c;
                            if(rec(arr))
                                return true;
                            else
                                arr[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        rec(board);
    }
};