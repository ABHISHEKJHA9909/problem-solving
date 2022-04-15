class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int r=arr.size(),c=arr[0].size();
        
        int rr=0,cc=0;
        for(int i=1;i<r;i++){
            if(arr[i][0]==0)
                rr=1;
        }
        
        for(int j=1;j<c;j++){
            if(arr[0][j]==0)
                cc=1;
        }
        
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(arr[i][j]==0){
                    arr[i][0]=0;
                    arr[0][j]=0;
                }
            }
        }
        
        for(int i=1;i<r;i++){
            if(arr[i][0]==0){
                for(int j=1;j<c;j++){
                    arr[i][j]=0;
                }
            }
        }
        
        for(int j=1;j<c;j++){
            if(arr[0][j]==0){
                for(int i=1;i<r;i++){
                    arr[i][j]=0;
                }
            }
        }
        
        if(arr[0][0]==0){
            for(int i=0;i<r;i++)
                arr[i][0]=0;
            for(int j=0;j<c;j++)
                arr[0][j]=0;
        }
        else{
            if(rr){
                for(int i=0;i<r;i++)
                    arr[i][0]=0;
            }
            if(cc){
                for(int j=0;j<c;j++)
                    arr[0][j]=0;
            }
        }
        
    }
};