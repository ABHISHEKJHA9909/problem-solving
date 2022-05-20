class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        
        if(arr[0][0]==1)
            arr[0][0]=-1;
        else
            arr[0][0]=1;
        
        for(int i=1;i<n;i++){
            if(arr[i][0]==1)
                arr[i][0]=-1;
            else
                arr[i][0]=arr[i-1][0];
        }
        
        for(int i=1;i<m;i++){
            if(arr[0][i]==1)
                arr[0][i]=-1;
            else
                arr[0][i]=arr[0][i-1];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j]==0){
                    if(arr[i][j-1]>0)
                        arr[i][j]+=arr[i][j-1];
                    if(arr[i-1][j]>0)
                        arr[i][j]+=arr[i-1][j];
                }
                else
                    arr[i][j]=-1;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<arr[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        if(arr[n-1][m-1]>0)
            return arr[n-1][m-1];
        return 0;
    }
};