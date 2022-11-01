class Solution {
public:

    int r,c;
    
    int down(vector<vector<int>>& arr,int j){
        int i=0;
        while(i!=r){
            if(arr[i][j]==1){
                if((j==c-1||arr[i][j+1]==-1))
                    return -1;
                else
                    j+=1;
            }
            else{
                if((j==0||arr[i][j-1]==1))
                    return -1;
                else
                    j-=1;
            }
            i+=1;
        }
        return j;
    }
    
    vector<int> findBall(vector<vector<int>>& arr) {
        c=arr[0].size(),r=arr.size();
        vector<int> res(c);
        
        for(int i=0;i<c;i++){
            res[i]=down(arr,i);
        }
        
        return res;
    }
};